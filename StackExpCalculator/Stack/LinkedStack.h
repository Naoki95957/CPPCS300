//Name      :   LinkedStack.h
//Author    :   Naoki Lucas
//Date      :   10/23/2019
//Desc      :   Node/link based stack

#include "Stack_ADT.h"
#include <ostream>
#ifndef LINKED_STACK_H
#define LINKED_STACK_H

///single link node
template<typename T>
struct Node
{
    T data = NULL;
    Node<T> * next = NULL;
};

///This is a stack class based on arrays
template<typename T>
class LinkedStack:public Stack_ADT<T>
{
    private:
        ///top most node
        Node<T> * head = NULL;
        ///current size of stack
        int currentSize = 0;
    public:
        ///constructor
        LinkedStack()
        {
            head = new Node<T>();
        }

        ///simply makes a new head-node
        void push(const T &data)
        {
            Node<T> * newNode = new Node<T>();
            newNode->data = data;
            newNode->next = head;
            head = newNode;
            ++currentSize;
        }

        ///removes head node
        void pop()
        {
            
            if(isEmpty())
            {
                throw std::exception("no, I won't let you. Becuase the stack is empty");
            }
            else
            {
                Node<T> * temp = head;
                head = head->next;
                delete temp;
            }
            --currentSize;
        }
        ///read and removes head node
        T top()
        {
            T data = head->data;
            pop();
            return data;
        }
        ///checks if empty
        bool isEmpty()
        {
            return currentSize == 0;
        }
        ///it's linked... it's never full
        bool isFull()
        {
            return false;
        } 
        ///destoryer if I ever copy stuff
        void destory()
        {
            while(!isEmpty())
            {
                Node<T> * temp = head;
                head = head->next;
                delete temp;
                --currentSize;
            }
        }

        friend std::ostream& operator<<(std::ostream& os, LinkedStack<T> &stack)
        {
            LinkedStack<T> copy = LinkedStack<T>();
            os << "<";
            bool pass = false;
            while(!stack.isEmpty())
            {
                if(pass) 
                {
                    os << ", ";
                }
                T data = stack.top();
                copy.push(data);
                os << data;
                pass = true;
            }
            os << ">";
            while(!copy.isEmpty())
            {
                stack.push(copy.top());
            }
            return os;
        }

        ///destructor
        ~LinkedStack()
        {
            destory();
        }

};

#endif
