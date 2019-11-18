#include <iostream>
using namespace std;
/*  Author: Fatma C Serce
    Date: Fall 2019
    Description: A sample linked list implementation which stores int values
*/

//creates a data structure, node, to store data and the link for the next node
struct node{
    int data;
    node *next;
};

//class definition for LinkedList ADT
class LinkedList{
    private:
        node *head, *last;
        int count;
    public:
        LinkedList(); //constructor to initialize an empty list
        LinkedList(LinkedList& list); //copy constructor
        int size() const;   //returns the number of items in the list
        void insert_last(int); //inserts to the end of the list
        void insert_first(int); //insert to the front of the list
        bool is_empty();    //returns true if it is empy, false otherwise
        int front();    //returns the item at the front of the list
        int lastItem();     //returns the last item in the list
        void remove(int);   //removes an item from the list
        int search(int);    //searches for an item and returns the index
        void insert(int, int); //insert an item to the given index
        int countItems(int); //counts the number of items that match the integer
        int sum(); //sum up elements
        void printMiddle(); //print the middle element
        void reverse(); //reverse the list
        friend ostream& operator<<(ostream& os, LinkedList& list); //overload << operator so that cout<<list prints the list
        void operator=(LinkedList& list); //overload = operator so that it basically does the same thing as copy constructor
        ~LinkedList(); //destructor to impload then burn and cremate the list
};

