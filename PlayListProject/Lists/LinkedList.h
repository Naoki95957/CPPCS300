//Name      :   LinkedList.h
//Author    :   Naoki Lucas
//Date      :   10/02/2019
//Desc      :   Double-linked list with index cache

#include <iostream>
#include "Node.h"

template <typename T>
///This struct is purely for my linkedlist
///This creates a relationship between a node and index
struct Cache{
    public:
    int index;
    ///The related node to some index
    Node<T> * pTail;
    Cache(int index, Node<T> * pTail)
    :index(index), pTail(pTail)
    {}
};

template <typename  T> 
///A double-linked list with index caching
class LinkedList
{
    private:
        ///Front most node
        Node<T> * pHeadNode = nullptr;
        ///Last most node
        Node<T> * pLastNode = nullptr;
        ///A node with value dedicated to index and location
        ///The tail will contain the node the related to said index
        Cache<T> * pCache = nullptr;
        ///reference count for the size of the list
        int count = 0;
    public:
        ///Create a double-linked list with index caching
        LinkedList();
        ///check to see if the list is empty
        bool isEmpty() const;
        ///get the size of the list
        int size() const;
        ///get the last most dataa
        T frontData() const;
        ///get the the front most data
        T lastData() const;
        ///get the front-most node
        Node<T>* getFrontNode() const;
        ///Get the last-most node
        Node<T>* getLastNode() const;
        ///This will make use of the cache to fetch the node index, nearest cache/front/tail
        Node<T> * fetch(int index);
        ///insert data at the front of the list
        void insertFirst(T);
        ///insert data at the back of the list
        void insertLast(T);
        ///insert an item to the given index
        void insert(T, int);
        ///Searches for an item and returns the index
        ///returns -1 if not found
        int searchFor(T);
        ///gets data at index
        T get(int);
        ///Move entitry from one index to another
        ///entity index, destination index
        void move(int, int);
        ///remove at index
        void remove(int);
        ///remove all equivalent to T
        ///returns the number of elements delete
        ///returns -1 if none was deleted
        int removeAll(T);
        ///deletes all allocated memory and empties out the list
        void destory();
        ~LinkedList();

        template <typename U>
        ///Prints the entire list
        friend std::ostream& operator<<(std::ostream& out, const LinkedList<U>& list);
};