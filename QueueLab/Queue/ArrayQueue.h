//Name      :   ArrayQueue.h
//Author    :   Naoki Lucas
//Date      :   10/23/2019
//Desc      :   Queue done with arrays (fixed size)

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#include "QueueADT.h"

///Array version of queue
template <typename T>
class ArrayQueue:public QueueADT<T>
{
    private:
        ///The array in which the data is stored
        T * arr;
        ///max size of the array
        int maxSize;
        ///utilization of the array
        int currentSize = 0;
        ///front index
        int front = 0;
    public:
        ///Constructor; defualt size is 100
        ArrayQueue(int size = 100)
        :maxSize(size)
        {
            arr = new T[size];
        }

        ///insert data into the queue
        void enqueue(T data)
        {
            if(!isFull())
            {
                arr[(front + currentSize++) % maxSize]  = data;
            }
        }

        ///retrieve and remove data 
        T dequeue()
        {
            if(isEmpty()) return NULL;
            T data = arr[front++];
            front %= maxSize;
            --currentSize;
            return data;
        }

        ///peek at front data
        T peek()
        {
            return arr[front];
        }

        ///destorys the array
        void destroy()
        {
            delete [] arr;
        }

        ///destructor
        ~ArrayQueue()
        {
            destroy();
        }

        ///check if array is empty
        bool isEmpty()
        {
            return currentSize == 0;
        }

        ///check if the array is full
        bool isFull()
        {
            return currentSize == maxSize;
        }

};
#endif