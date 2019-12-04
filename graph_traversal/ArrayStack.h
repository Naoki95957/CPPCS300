//============================================================================
// Name        : ArrayStack.h
// Author      : Fatma C Serce
// Version     : 1.0
// Description : Stack implementation with array data structure
//============================================================================

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include "Stack.h"
#include <iostream>

using namespace std;

template<class T>
class ArrayStack:public StackADT<T>{
    private:
        T* pstack;      //stack in array form
        int stack_top;  //index for top of the stack
        int size;       //maximum size of the stack

        void copyStack(const ArrayStack<T>&); //utility function to copy one stack into another
    public:
        ArrayStack(int=100);    //initialize an empty stack with given size, or with default=100
        ArrayStack(const ArrayStack<T>&);   //copy constructor
        void push(const T&);    //push an item to the top of the stack
        void pop();             //removes the item from the top of the stack
        T top();                //returns the item at the top of the stack
        void destroy();         //destroys the stack and make it an empty stack
        bool isEmpty();         //returns true if the stack is empty
        bool isFull();          //return true if the stack is full
        ArrayStack<T>& operator=(const ArrayStack<T>&); //assignment operator overloading
        template <class U>
        friend ostream& operator<<(ostream& os, const ArrayStack<U>& stack);
        ~ArrayStack();          //destructor
};

//initializes an empty stack
//an array is created and stack_top is initialized to 0.
template<class T>
ArrayStack<T>::ArrayStack(int _size){
    size = _size;
    pstack = new T[size]; 
    stack_top = 0;  
}

//destructor for the stack
//destroys the stack and make it an empty stack
template<class T>
ArrayStack<T>::~ArrayStack(){
    destroy();
}

//copy constructor that creates a stack from the other
template<class T>
ArrayStack<T>::ArrayStack(const ArrayStack<T>& other){
    copyStack(other);
}

//utility function that copies from stack into the current
//state of stack object should be same in both copies
//state of stack include the data in the array and stack_top value
template<class T>
void ArrayStack<T>::copyStack(const ArrayStack<T>& other){
    if(!isEmpty()) //if the current stack object is not empty, destroy it before copy from the other 
        destroy();
    pstack = new T[other.size]; //create a new stack object
    stack_top = other.stack_top;    
    for(int i=0;i<stack_top;i++){
        pstack[i] = other.pstack[i];
    }
}

//operator overloading for assignment(=) operator that does deep copy
template<class T>
ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& other){
    if(this!=*other)
        copyStack(other);
    return *this;
}

//inserts a new item to the top of the stack
//throws an exception if it is already full
template<class T>
void ArrayStack<T>::push(const T& item){
    if(isFull()) 
        throw "Stack is already full";
    pstack[stack_top++] = item;
}

//removes the item at the top of the stack
//throws an exception if it is already empty
template<class T>
void ArrayStack<T>::pop(){
    if(isEmpty()) 
        throw "Stack is empty";
    stack_top--;
}

//returns the item at the top of the stack, it DOES NOT remove it
//throws an exception if it is already empty
template<class T>
T ArrayStack<T>::top(){
    if(isEmpty()) 
        throw "Stack is empty";
    return pstack[stack_top-1];
}

//returns true if the stack is empty
template<class T>
bool ArrayStack<T>::isEmpty(){
    return stack_top==0;
}

//returns true if the stack is full
template<class T>
bool ArrayStack<T>::isFull(){
    return stack_top==size;
}

//destroys the stack and make it an empty stack
template<class T>
void ArrayStack<T>::destroy(){
    delete[] pstack;
    stack_top=0;
}

//overload operator<< so that stack instance can be used with << operator
template <class U>
ostream& operator<<(ostream& os, const ArrayStack<U>& stack){
    for(int i=0;i<stack.stack_top;i++){
        os<<stack.pstack[i]<<" ";
    }
    os<<endl;
    return os;
}

#endif