//Name      :   LinkedList.cpp
//Author    :   Naoki Lucas
//Date      :   10/02/2019
//Desc      :   Double-linked list with index cache

#include <iostream>
#include "LinkedList.h"
#include "Node.h"

template <typename T>
LinkedList<T>::LinkedList()
{
    pHeadNode = pLastNode = nullptr;
    count = 0;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return count == 0;
}

template <typename T>
int LinkedList<T>::size() const
{
    return count;
}

template <typename T>
T LinkedList<T>::frontData() const
{
    return pHeadNode->data;
}

template <typename T>
T LinkedList<T>::lastData() const
{
    return pLastNode->data;
}


template <typename T>
Node<T>* LinkedList<T>::getFrontNode() const
{
    return LinkedList<T>::pHeadNode;
}

template <typename T>
Node<T>* LinkedList<T>::getLastNode() const
{
    return LinkedList<T>::pLastNode;
}

template <typename T>
Node<T>* LinkedList<T>::fetch(int index)
{
    Node<T> * node;
    //if cache hasn't been used yet
    if(pCache == nullptr)
    {
        if(count < 2 * index)
        {
            //tail/backward
            node = pLastNode;
            for(int i = 0; i < (count - index) - 1; ++i)
            {
                node = node->head;
            }
        }
        else
        {
            //head/forward
            node = pHeadNode;
            for(int i = 0; i < index; ++i)
            {
                node = node->tail;
            }
        }
        
    }
    //This sees if it's better to run off head or off cache
    else if((pCache->index) < 2 * index)
    {   
        //this see if it's better to run off tail or cache
        if((count - index < (index - (pCache->index))))//run via tail
        {
            node = pLastNode;
            for(int i = 0; i < (count - index) - 1; ++i)
            {
                node = node->head;
            }
        }
        else//fetch via cache
        {
            if(index > (pCache->index))//forward
            {
                node = pCache->pTail;
                for(int i = pCache->index; i < index; ++i)
                {
                    node = node -> tail;
                }
            }
            else//backward
            {
                node = pCache->pTail;
                for(int i = index; i < (pCache->index); ++i)
                {
                    node = node -> head;
                }
            }
            
        }
        
    }   
    else//fetch via head
    {
        node = pHeadNode;
        for(int i = 0; i < index; ++i)
        {
            node = node->tail;
        }
    }
    if(pCache != nullptr)
    {
        delete pCache;
    }
    pCache = new Cache<T>(index, node);
    return node;
}
template <typename T>
void LinkedList<T>::insertFirst(T data)
{
    //create new node
    Node<T> * newNode = new Node<T>(data, nullptr, pHeadNode);
    if(pHeadNode == nullptr)
    {
        pHeadNode = pLastNode = newNode;
        newNode->head = nullptr;
    }
    else
    {   
        pHeadNode->head = newNode;
        newNode->tail = pHeadNode;
        pHeadNode = newNode;
    }
    ++count;
    if(pCache != nullptr)
    {
        ++(pCache->index);
    }
}

template <typename T>
void LinkedList<T>::insertLast(T data)
{ 
    //create new node
    Node<T> * newNode = new Node<T>(data, pLastNode, nullptr);
    if(pHeadNode == nullptr)
    {
        pHeadNode = pLastNode = newNode;
        newNode->head = nullptr;
    }
    else
    {    
        pLastNode->tail = newNode;
        newNode->head = pLastNode;
        pLastNode = newNode;
    }
    ++count;
}

template <typename T>
T LinkedList<T>::get(int index)
{
    return (LinkedList<T>::fetch(index))->data;
}

template <typename T>
void LinkedList<T>::insert(T data, int index){
    if(index == 0)
    {
        insertFirst(data);
    }
    else if(index >= count - 1)
    {
        insertLast(data);
    }
    else
    {
        //this is the current residency of that index
        Node<T>* node = fetch(index);
        //creates new data with head and tail
        Node<T>* newNode = new Node<T>(data, node->head, node);
        //attaches the back of the node infront of the data to this index
        node->head->tail = newNode;
        //attaches the front of the node behind the data to this index
        node->head = newNode;
        ++count;
    }
    
    //this condition is to adjust the index only if the index
    //of the pCache is actually impacted
    if(pCache != nullptr)
    {
        if(pCache->index >= index)
        {
            ++(pCache->index);
        }
    }
}

template <typename T>
int LinkedList<T>::searchFor(T data)
{
    if(count == 0)
    {
        return -1;
    }
    else
    {
        Node<T> * node = pHeadNode;
        int i = 0;
        while(node != nullptr)
        {
            if(node->data == data)
            {
                return i;
            }
            node = node->tail;
            ++i;
        }
        //couldn't find it
        return -1;
    }
}

template <typename T>
void LinkedList<T>::move(int itemIndex, int destinationIndex)
{
    if(itemIndex == destinationIndex)
    {
        return;
    }
    if((itemIndex > -1 && itemIndex < count)
        && (destinationIndex > -1 && destinationIndex < count))
    {
        Node<T> * oldNode = fetch(itemIndex);
        T * newNodeData = new T(oldNode->data);
        remove(itemIndex);
        insert(*newNodeData, destinationIndex);
    }
    else
    {   
        //one or both indices are out of bounds
        return;
    }
    
}

template <typename T>
void LinkedList<T>::remove(int index)
{
    Node<T> * node = fetch(index);
    //if it's the only entity
    if(count == 1)
    {
        pHeadNode = pLastNode = nullptr;
    }
    //if it's the head node
    else if(index == 0)
    {
        pHeadNode = node->tail;
        pHeadNode->head = nullptr;
    }
    //if it's the last node
    else if(index == count - 1)
    {   
        pLastNode->head->tail = nullptr;
        pLastNode = node->head;
    }
    else
    {
        //attaches the front node's back to the one behind index
        node->head->tail = node->tail;
        //attaches the back node's front to the one infront of index
        node->tail->head = node->head;
    }

    delete node;
    --count;

    //this condition is to adjust the index only if the index
    //of the pCache is actually impacted
    if(pCache->index > index)
    { 
        --(pCache->index);
    }
}

template <typename T>
int LinkedList<T>::removeAll(T data)
{
    int accumulation = 0;
    for(int i = 0; i < count; ++i)
    {
        if(fetch(i)->data == data)
        {
            remove(i);
            //prevents skipping if values are back to back
            --i;
            ++accumulation;
        }
    }
    return accumulation > 0 ? accumulation : -1;
}

template <typename T>
void LinkedList<T>::destory()
{
    Node<T> *temp;
    while(pHeadNode != nullptr)
    {
        temp = pHeadNode;
        pHeadNode = pHeadNode->tail;
        delete temp;
        --count;
    }
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    destory();
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T>& list)
{
    //if nothing is present
    if(list.isEmpty())
    {
        out << "{}";
    }
    else
    {
        out << "{";
        Node<T> * node = list.getFrontNode();
        //if something is attached
        while(node->tail != nullptr)
        {
            out << node->data << ", ";
            node = node->tail;
        }
        //print the last node's contents
        out << node->data << "}";
    }
    return out;
}