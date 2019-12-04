/*
    Author: Fatma C Serce
    Date: October, 2019
    Description: This is a queue implementation using array data structure. 
    ArrayQueue class provides implementation for all abstract functions defined
    in QueueADT abstract class.
*/

#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE

#include <iostream>
#include "QueueADT.h"
using namespace std;

template <class T>
class ArrayQueue:public QueueADT<T>{

    private:
        T *data;    //array to store queue content
        int size;   //maximum capacity of the array-based queue
        int count;  //number of items in the queue
        int front;  //index referring to the front of the queue
        int rear;   //index referring to the end of the queue

    public:

        ArrayQueue(int _size=100){ //default size of the array is set to 100
            size = _size;
            count = 0;
            front = 0;      //front is initialized to the first index of the array;
            rear = size -1; //rear is initialized to the last index of the array
            data = new int[size]; //dynamically creates the array
        }

        //copy constructor
        ArrayQueue(ArrayQueue<T>& other){
            copyQueue(other);
        }

        //assignment operator
        ArrayQueue<T>& operator=(ArrayQueue<T>& other){
            if(this != &other){
                copyQueue(other);
            }

            return *this;
        }

        //helper function to copy from other queue object into the current one
        void copyQueue(ArrayQueue<T>& other){
            size = other.size;
            count = other.count;
            front = other.front;
            rear = other.rear;
            data = new T[other.size];
            for(int i = 0; i < size; i++){
                data[i] = other.data[i];
            }
        }

        //insert a new item to the end of the queue
        void enqueue( const T& item){
            if(!isFull()){
                rear = (rear + 1) % size; //insert updates rear index using circular array
                data[rear] = item;
                count++;
            }
        }

        //returns the item at the front of the queue
        T qfront(){
            if(!isEmpty())
                return data[front];
            return NULL;
        }

        //removes the item from the front of the queue
        void dequeue(){
             if(!isEmpty()){
                front = (front + 1) % size;//deleting an item updates front index using a circular array
                count--;
            }           
        }

        //returns true if the queue is empty, returns false otherwise
        bool isEmpty(){
            return count==0;
        }

         //returns true if the queue is full, returns false otherwise
        bool isFull(){
            return count == size;
        }

        //friend function to overload operator (<<)
        template <class U>
        friend ostream& operator<<(ostream& os, ArrayQueue& q)
        {
             return q.display(os);
        }

        //overrides display function defined in the QueueADT
        ostream& display(ostream& os){
            if(!isEmpty()){
                for(int i=0;i<count;i++){
                    os<<data[(front+i)%size]<<" ";
                }
            }
            os<<endl;
            return os;
        }

        //destroys the queue object
        ~ArrayQueue(){
            delete[] data;
        }

};

#endif