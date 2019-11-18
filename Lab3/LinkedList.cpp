#include <iostream>
#include "LinkedList.h"

//constructor to initialize an empty list
LinkedList::LinkedList(){
    head = last = NULL;
    count = 0;
}
//returns the number of items in the list
int LinkedList::size() const{
    return count;
}   

LinkedList::~LinkedList()
{
    int size = count;
    node * temp = head;
    for(int i = 0; i < size; ++i)
    {
        node * toDel = temp;
        temp = temp->next;
        delete toDel;
    }
    head = last = NULL;
}

//inserts to the end of the list
void  LinkedList::insert_last(int item){
    node* newNode = new node;
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
void  LinkedList::insert_first(int item){
    node* newNode = new node;
    newNode->data = item;
    newNode->next = head;
    head = newNode;
    if(last==NULL)
        last = head;
    count++;
} 
//insert an item to the given index
void LinkedList::insert(int item, int index){
    if(index>count || index<0) 
        return;
    if(index==0)
        insert_first(item);
    else if(index==count)
        insert_last(item);
    else{    
        node *temp = head;
        while(index--){
            temp = temp->next;
        }
        node *newNode = new node;
        newNode->data = item;
        newNode->next = temp->next;
        temp->next = newNode;
        count++;
    }
}

//searches for an item and returns the index
int LinkedList::search(int item){
  if(is_empty()) return -1;
  node *temp = head;
  int index = 0;
  while(temp!=NULL && temp->data!=item){//keep searching while there is more item and item is not found
    temp = temp->next;
    index++;
  }
  if(temp!=NULL) //item found
    return index;

  return -1; //item not found
}

//removes an item from the list
//CASE0: list is empty
//CASE1: remove the first item
//CASE2: remove the only item
//CASE3: remove the last item
//CASE4: remove the item in between
//CASE5: item not found
void LinkedList::remove(int item){
	if(is_empty()) return;

	if(head->data == item){ //remove the first item
        node* temp = head;
        head= head->next;
        if(head == NULL){ //remove the only item
            last = NULL;
        }
        delete temp;
        count--;
              
	}else{
		node *prev = head;
		node *current = head->next;
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

//overload << operator so that cout<<list prints the list
ostream& operator<<(ostream& os, LinkedList& list){
    node* temp = list.head;
    while(temp!=NULL){
        os<<temp->data<<" ";
        temp = temp->next;
    }
    os<<endl;
    return os;
}

void LinkedList::operator=(LinkedList& target)
{   
    int currentCount = LinkedList::count;
    node * thisTemp = LinkedList::head;
    node * targetTemp = target.head;
    node * handoff = NULL;
    for(int i = 0; i < target.count; ++i)//old list is = or smaller in size
    {
        if(i < currentCount)
        {   
            if(i == target.count - 1)
            {
                thisTemp->data = targetTemp->data;
                handoff = thisTemp;
                thisTemp->next = NULL;
            }
            else
            {
                thisTemp->data = targetTemp->data;
                thisTemp = thisTemp->next;
                targetTemp = targetTemp->next;
            }
        }
        else
        {
            insert_last(targetTemp->data);
            targetTemp = targetTemp->next;
        }
    }
    currentCount = LinkedList::count;
    LinkedList::last = thisTemp;
    for(int i = target.count; i < currentCount; ++i)//old list is larger
    {
        node * toDel = handoff;
        handoff = handoff->next;
        delete toDel;
        -- LinkedList::count;
    }
}

LinkedList::LinkedList(LinkedList& target)
{   
    head = last = NULL;
    count = 0;

    node * targetTemp = target.head;
    int size = target.count;
    for(int i = 0; i < size; ++i)
    {
        insert_last(targetTemp->data);
        targetTemp = targetTemp->next;
    }
}

//returns true if it is empy, false otherwise
bool LinkedList::is_empty(){
    return head==NULL;
}   
//returns the item at the front of the list
int LinkedList::front(){
    return head->data;
}   

///counts the number of matching items
int LinkedList::countItems(int target)
{
    int matches = 0;
    node* temp = head;
    while(temp!=NULL){
        if(temp->data == target)
        {
            ++matches;
        }
        temp = temp->next;
    }
    return matches;
}

int LinkedList::sum()
{ 
    int summation = 0;
    node* temp = head;
    while(temp!=NULL){
        summation += temp->data;
        temp = temp->next;
    }
    return summation;
}

void LinkedList::printMiddle()
{
    node* temp = head;
    int target = count / 2;
    for(int i = 0; i < target; ++i)
    {
        temp = temp->next;
    }
    std::cout << temp->data << std::endl;
}

void LinkedList::reverse()
{ 
    int size = count;
    int * data = new int [size];
    node * temp = head;
    for(int i = 0; i < size; ++i)
    {
        int val = temp->data;
        temp = temp->next;
        data[i] = val;
    }
    temp = head;
    for(int i = size - 1; i > -1; --i)
    {
        temp->data = data[i];
        temp = temp->next;
    }
}




//returns the item at the back of the list
int LinkedList::lastItem(){
    return last->data;
}    



