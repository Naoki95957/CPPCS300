/*  Author: Fatma C Serce
    Date: Fall 2019
    Description: A sample template linked list implementation 
*/

//creates a data structure, node, to store data and the link for the next node
#include <iostream>
using namespace std;

template <class T>
struct node{
    T data;
    node<T> *next;
};

//class definition for LinkedList ADT
template <class T>
class LinkedList{
    private:
        node<T> *head, *last;
        int count;
    public:
        LinkedList(); //constructor to initialize an empty list
        int size() const;   //returns the number of items in the list
        void insert_last(T); //inserts to the end of the list
        void insert_first(T); //insert to the front of the list
        bool is_empty();    //returns true if it is empy, false otherwise
        T front();    //returns the item at the front of the list
        T lastItem();     //returns the last item in the list
        void remove(T);   //removes an item from the list
        bool search(T);    //searches for an item and returns the index
        template <class U>
        friend ostream& operator<<(ostream& os, LinkedList<U>& list){ //overload << operator so that cout<<list prints the list
            node<T>* temp = list.head;
            while(temp!=NULL){
                os<<temp->data<<" ";
                temp = temp->next;
            }
            os<<endl;
            return os;

        }
};

//constructor to initialize an empty list
template <class T>
LinkedList<T>::LinkedList(){
    head = last = NULL;
    count = 0;
}
//returns the number of items in the list
template <class T>
int LinkedList<T>::size() const{
    return count;
}   

//inserts to the end of the list
template <class T>
void  LinkedList<T>::insert_last(T item){
    node<T>* newNode = new node<T>;
    newNode->data = item;
    newNode->next = NULL;
    if(head == NULL)
        head = last = newNode;
    else{
        last->next = newNode;
        last = newNode;
    }
    count++;
}

//insert to the front of the list
template <class T>
void  LinkedList<T>::insert_first(T item){
    node<T>* newNode = new node<T>;
    newNode->data = item;
    newNode->next = head;
    head = newNode;
    if(last==NULL)
        last = head;
    count++;
} 

//searches for an item and returns the index
template <class T>
bool LinkedList<T>::search(T item){
  if(is_empty()) return false;
  node<T> *temp = head;
  int index = 0;
  while(temp!=NULL && temp->data!=item){//keep searching while there is more item and item is not found
    temp = temp->next;
    index++;
  }
  if(temp!=NULL) //item found
    return true;

  return false; //item not found
}

//removes an item from the list
//CASE0: list is empty
//CASE1: remove the first item
//CASE2: remove the only item
//CASE3: remove the last item
//CASE4: remove the item in between
//CASE5: item not found
template <class T>
void LinkedList<T>::remove(T item){
	if(is_empty()) return;

	if(head->data == item){ //remove the first item
        node<T>* temp = head;
        head= head->next;
        if(head == NULL){ //remove the only item
            last = NULL;
        }
        delete temp;
        count--;
              
	}else{
		node<T> *prev= head;
		node<T> *current = head->next;
		while(current!=NULL && current->data!=item){ //search for an item
			prev = current;
            current = current->next;
        }
		if (current!=NULL){ //item is found 
			prev->next = current->next;
			if (current==last) //remove the last item
				last = prev;
			delete current;
			count--;
		}
        //returns if it is not found
    }
}  

//returns true if it is empy, false otherwise
template <class T>
bool LinkedList<T>::is_empty(){
    return head==NULL;
}   
//returns the item at the front of the list
template <class T>
T LinkedList<T>::front(){
    return head->data;
}   

//returns the item at the back of the list
template <class T>
T LinkedList<T>::lastItem(){
    return last->data;
}    





