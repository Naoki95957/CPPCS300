//Name      :   ArrayStack.h
//Author    :   Naoki Lucas
//Date      :   10/18/2019
//Desc      :   Array based stack

#include "Stack_ADT.h"
#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

///This is a stack class based on arrays
template<typename T>
class ArrayStack:public Stack_ADT<T>
{
private:
    ///initializer for the size of the array
    int max_size = 100;
    ///tells us the current utilization of the array
    int current_size = -1;
    ///Array for the data
    T * arr;
public:
    ///Create a new array stack with size
    ArrayStack(int size = 100)
    :max_size(size)
    {
        arr = new T[max_size];
    }
    ///Push data to stack
    void push(const T &data)
    {
        if(isFull())return;
        arr[++current_size] = data;
    }
    ///pop data from stack
    void pop()
    {   
        if(isEmpty())return;
        arr[current_size--] = 0;
    }
    ///read and pop data from stack
    T top()
    {
        if(isEmpty())return NULL;
        return arr[current_size--];
    }
    ///check if stack is emtpy
    bool isEmpty()
    {
        return current_size == -1;
    }
    ///check if stack is full
    bool isFull()
    {
        return current_size == max_size - 1;
    }
    ///destroy stack
    ~ArrayStack()
    {
        for(int i = 0; i < max_size; ++i)
        {
            delete (arr + i);
        }
    }
};

#endif
