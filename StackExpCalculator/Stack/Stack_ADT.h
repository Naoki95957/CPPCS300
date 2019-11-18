#ifndef STACK_ADT
#define STACK_ADT
template <typename T>
class Stack_ADT
{
public:
    ///Add item to the stack
    virtual void push(const T&) = 0;
    ///remove top element from the stack
    virtual void pop() = 0;
    ///return the top element from the stack
    virtual T top() = 0;
    ///return true if the stack is empty
    virtual bool isEmpty() = 0;
    ///return true if the stack is full
    virtual bool isFull() = 0;
};
#endif