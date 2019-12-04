//============================================================================
// Name        : StachADT.h
// Author      : Fatma C Serce
// Version     : 1.0
// Description : Stack Abstract Data Type
//============================================================================

#ifndef STACK_ADT
#define STACK_ADT

template <class T>
class StackADT{
    //Function to add a new item to the stack
	//Precondition: Stack exists and is not full
	//Post Condition: Stack is changed and the new item
	//is added to the top of the stack
    virtual void push(const T&) = 0;

    //Function to remove the top element from the stack
	//Precondition: Stack exists and is not empty
	//Post Condition: Stack is changed and the top element is removed from the stack
    virtual void pop() = 0;

    //Function to return the top element from the stack
	//Precondition: Stack exists and is not empty
	//Post Condition: If the stack is empty, the program returns, otherwise,
	//the top element of the stack is returned
    virtual T top() = 0;

    //Function to determine whether the stack is empty
	//Post Condition: Returns 1 of the stack is empty
	//otherwise returns 0
    virtual bool isEmpty() = 0;

	//Function to determine whether the stack is full
	//Post Condition: Returns 1 of the stack is full
	//otherwise returns 0
    virtual bool isFull() = 0;

};

#endif