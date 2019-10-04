//Name      :   Node.h
//Author    :   Naoki Lucas
//Date      :   10/02/2019
//Desc      :   Node to hold double structure in linked list
#ifndef NODE_H
#define NODE_H

template <typename T>
///Generic node structure with double-link
class Node
{
public:
    ///Actual contents
    T data;
    ///Forward node reference
    Node<T> * head;
    ///Backward node reference
    Node<T> * tail;
    ///Double-link node with data, head, and tail params
	Node(T data, Node<T> * head, Node<T> * tail)
    :Node::data(data), Node::head(head), Node::tail(tail)
    {
        
    }
};
#endif