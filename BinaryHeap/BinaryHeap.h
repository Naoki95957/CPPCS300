/*
    Author: Fatma C Serce
    Date: October, 2019
    Description: This is an array-based implementation
    of a Binary Heap. This is a min-heap implementation where 
    the highest priority type has the lowest value.

*/
#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class BinaryHeap{
    T *array;       //binary heap is represented and stored in an array
    int maxSize;    //maximum capacity of the priority queue
    int count;      //the number of items in the priority queue

    public:
        BinaryHeap(int _size=100);
        void insert(T& item);
        bool isEmpty();
        bool isFull();
        T getMin();
        void deleteMin();

        ~BinaryHeap();
        //overloads operator(<<)
        template <class U>
        friend ostream& operator<<(ostream& os, const BinaryHeap<U> &heap){
            for(int i=1;i<=heap.count;++i){
                os<<heap.array[i]<<" ";
            }
            os<<endl;
            return os;
        }

    private:
        void percolate_loop(int hole)
        {
            while(hole * 2 <= count)
            {
                int hole_val = array[hole];
                int left = array[hole * 2];
                int right = array[hole * 2 + 1];

                if(right < hole_val)
                {
                    array[hole * 2 + 1] = hole_val;
                    array[hole] = right;
                    hole *= 2;
                    ++hole;
                }
                else if(left < hole_val)
                {
                    array[hole * 2] = hole_val;
                    array[hole] = left;
                    hole *= 2;
                }
                else
                {
                    //in order
                    return;
                }
            }
        }

        void percolate_recursive(int hole)
        {   
            if(hole >= count)
                return;

            int hole_val = array[hole];
            int left = array[hole * 2];
            int right = array[hole * 2 + 1];
            
            //this will be used to identify if right child doesn't exist
            bool bounds = (hole * 2 > count);

            if(left < hole_val && !bounds)
            {
                if(left < right)
                {
                    array[hole] = left;
                    array[hole * 2] = hole_val;
                    percolate_recursive(hole * 2);
                }
                else
                {
                    array[hole] = right;
                    array[hole * 2 + 1] = hole_val;
                    percolate_recursive(hole * 2 + 1);
                }
            }
            else
            {
                //this scenario means it's comparing last
                if(left < hole_val)
                {
                    array[hole] = left;
                }
            }
        }
};

//constructor
template <class T>
BinaryHeap<T>::BinaryHeap(int _size){
    maxSize = _size;
    array = new T[_size]; //dynamically create an array with the given size
    count = 0;
}

//destructor
template <class T>
BinaryHeap<T>::~BinaryHeap(){
    delete[] array;
}

//insert a new item into the priority queue
//heap will re-organizes its content so that minimum items 
//is stored at the front of the queue
template <class T>
void BinaryHeap<T>::insert(T& item){
    if(isFull())
        throw overflow_error("queue is full");

    array[0] = item;

    int hole = ++count;
    for(;item<array[hole/2];hole/=2){
        array[hole] = array[hole/2];
    }
    array[hole] = item;
}

//returns true if the priority queue is empty, 
//return false otherwise
template <class T>
bool BinaryHeap<T>::isEmpty(){
    return count==0;
}

//returns true if the priority queue is full, 
//return false otherwise
template <class T>
bool BinaryHeap<T>::isFull(){
    return count==maxSize;
}

//returns the minimum (highest priority) in the queue
template <class T>
T BinaryHeap<T>::getMin(){
    if(!isEmpty())
    {
        return array[1];
    }
    else
    {
        return NULL;   
    }
}

template <typename T>
void BinaryHeap<T>::deleteMin()
{
    array[1] = array[count--];
    //percolate_loop(1);
    percolate_recursive(1);
}



#endif