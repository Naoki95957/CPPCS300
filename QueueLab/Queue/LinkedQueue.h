//Name      :   LinkedQueue.h
//Author    :   Naoki Lucas
//Date      :   10/23/2019
//Desc      :   Queue done with single-link nodes (non-fixed size)

#include "QueueADT.h"
#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

///single link node
template<typename T>
struct Node
{
    T data;
    Node<T> * next;
};

template<typename T>
class LinkedQueue:public QueueADT<T>
{
    private:
        ///front node for de-queue
        Node<T> * front = NULL;
        ///last node for appending
        Node<T> * last = NULL;
    public:
        ///constructor for linkedQueue 
        ///can pass in a number for fun
        LinkedQueue(int size = 0)
        {
            front = NULL;
            last = NULL;
        }

        ///adds item to queue
        void enqueue(T data)
        {
            if(isEmpty())
            {
                last = new Node<T>();
                last->data = data;
                front = last;
            }
            else
            {
                Node<T> * newNode = new Node<T>();
                newNode->data = data;
                last->next = newNode;
                last = newNode;
            }
        }

        ///gets item from queue and removes it
        T dequeue()
        {
            if(isEmpty())return NULL;
            Node<T> * temp = front;
            T data = front->data;
            front = front->next;
            delete temp;
            return data;
        }

        ///peeks at the front data
        T peek()
        {
            return front->data;
        }
        
        ///deletes the queue
        void destory()
        {
            while (front != NULL)
            {
                Node<T> * temp = front->next;
                delete front;
                front = temp;
            }
        }

        ///destoryer
        ~LinkedQueue()
        {
            destory();
        }

        ///checks if the queue is empty
        bool isEmpty()
        {
            return front == NULL;
        }

        bool isFull() {return false;}

};

#endif