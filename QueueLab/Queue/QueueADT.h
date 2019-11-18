//Name      :   QueueADT.h
//Author    :   Naoki Lucas
//Date      :   10/23/2019
//Desc      :   Queue abstract

#ifndef QUEUE_ADT
#define QUEUE_ADT
#include <ostream>
///abstract for Queue
template<typename T> 
class QueueADT
{
    ///insert objects
    virtual void enqueue(int) = 0;
    ///output objects
    virtual T dequeue() = 0;
    ///peek at object
    virtual T peek() = 0;
    ///checks if empty
    virtual bool isEmpty() = 0;
    ///checks if full
    virtual bool isFull() = 0;
};

#endif