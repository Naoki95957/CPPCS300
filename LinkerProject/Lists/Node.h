#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
public:
    T data;
    Node<T> * head;
    Node<T> * tail;
	Node(T data, Node<T> * head, Node<T> * tail)
    :Node::data(data), Node::head(head), Node::tail(tail)
    {
        
    }
};
#endif