/*
    Author: Fatma C Serce
    Date: October, 2019
    Description: This is simple implementation of Queue abstract data type. 
    The class provide abstract functions for the following operations:
    - enqueue
    - dequeue
    - isEmpty
    - isFull
    
    The class also provides a concrete method called, display, which writes the contents
    of queue object into the given output stream object
*/

#ifndef QUEUE_ADT
#define QUEUE_ADT
#include <iostream>

using namespace std;

template <class T>
class QueueADT{
    public:
        virtual void enqueue(const T&) = 0;
        virtual void dequeue() = 0;
        virtual T qfront() = 0;
        virtual bool isEmpty() = 0;  
        virtual bool isFull() = 0;  
        virtual ostream& display(ostream&) = 0;
};

#endif