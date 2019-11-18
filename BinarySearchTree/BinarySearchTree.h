/*
    Author: Fatma C Serce
    Date: October, 2019
    Description: This is a template implemetation for Binary Search Tree
*/

#ifndef BST_H
#define BST_H

#include <iostream>

using namespace std;

//structure defining the node in a binary search tree
//a node keeps the address of left child, address of right child
//and the data (key-value)
template <class T>
struct treenode{
    T data;
    treenode<T> *left;
    treenode<T> *right;
};

//class definition for BinarySearchTree
template <class T>
class BinarySearchTree{
    private:
        treenode<T> *root;
    public: 
        //public interface: functions available to outside

        BinarySearchTree();
        BinarySearchTree(const BinarySearchTree& tree);
        BinarySearchTree& operator=(BinarySearchTree *ptr);
        treenode<T>* copy(treenode<T> *ptr);
        void insert(T& item);
        bool search(T& item);
        void remove(T& item);
        T max();
        T min();
        int height();
        void printInOrder();
        void printPreOrder();
        void printPostOrder();
        ~BinarySearchTree();
    private: 
        //private function to start recursive function calls

        void tree_insert(treenode<T>*&, T&); //need to pass pointer reference to update the links on the treenode
        bool tree_search(treenode<T>*, T&);
        void tree_remove(treenode<T>*&, T&);
        T tree_max(treenode<T>*);
        T tree_min(treenode<T>*);
        int findMax(int , int);
        int tree_height(treenode<T>*);
        void tree_printInOrder(treenode<T>*);
        void tree_printPreOrder(treenode<T>*);
        void tree_printPostOrder(treenode<T>*);
        void destroy(treenode<T>*&);

};

//constructor for Binary Search Tree
//creates and empy tree (root = NULL) 
template <class T>
BinarySearchTree<T>::BinarySearchTree(){
    root = NULL;
}

//copy constructor
template <class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& tree){

    root = copy(tree.root);
}

//assignment operator
template <class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(BinarySearchTree<T> *ptr){
    if(ptr !=NULL){
        destroy();
        root = copy(ptr);
    }

    return *this;
}


// helper recursive function to copy from other queue object into the current one
template <class T>
treenode<T>* BinarySearchTree<T>::copy(treenode<T> *ptr) {
    if (ptr != NULL){
        treenode<T> *newnode = new treenode<T>;
        newnode->data = ptr->data;
        newnode->left = copy(ptr->left);
        newnode->right = copy(ptr->right);
        return newnode;
    }
    return NULL;
}

//initiates call for recursive insert function 
template <class T>
void BinarySearchTree<T>::insert(T& item){
    tree_insert(root, item);
}

//inserts a new node into the tree
template <class T>
void BinarySearchTree<T>::tree_insert(treenode<T> *& p, T& item){
    if(p == NULL){
        p = new treenode<T>;
        p->data = item;
        p->left = NULL;
        p->right = NULL;
    }else if(item<p->data){     
        tree_insert(p->left, item);
    }else if(item>p->data){
        tree_insert(p->right, item);
    }
}

template <class T>
void BinarySearchTree<T>::printPreOrder(){
    tree_printPreOrder(root);
}

//traverses the tree in pre order format
//Root Left Right
template <class T>
void BinarySearchTree<T>::tree_printPreOrder(treenode<T> * p){
    if(p != NULL){
        cout<<p->data<<" ";
        tree_printPreOrder(p->left);
        tree_printPreOrder(p->right);
    }
}

template <class T>
void BinarySearchTree<T>::printPostOrder(){
    tree_printPostOrder(root);
}

//traverses the tree in pre order format
//Root Left Right
template <class T>
void BinarySearchTree<T>::tree_printPostOrder(treenode<T> * p){
    if(p != NULL){
        tree_printPostOrder(p->left);
        tree_printPostOrder(p->right);
        cout<<p->data<<" ";
    }
}

template <class T>
void BinarySearchTree<T>::printInOrder(){
    tree_printInOrder(root);
}

//traverses the tree in pre order format
//Root Left Right
template <class T>
void BinarySearchTree<T>::tree_printInOrder(treenode<T> * p){
    if(p != NULL){
        tree_printInOrder(p->left);
        cout<<p->data<<" ";
        tree_printInOrder(p->right);
    }
}


//a helper function to find the maximum number between two integers
template <class T>
int BinarySearchTree<T>::findMax(int x, int y){
    if(x>y) 
        return x;
    return y;
}

template <class T>
int BinarySearchTree<T>::height(){
    return tree_height(root)-1;
}


//returns the height of the tree
//Assumption: when the tree is empty and there is only one node, height is zero.
template <class T>
int BinarySearchTree<T>::tree_height(treenode<T> * p){
    if(p == NULL)
        return 0;
    return 1 + findMax(tree_height(p->left), tree_height(p->right));
}

template <class T>
T BinarySearchTree<T>::max(){
   return tree_max(root);
}

//finds and returns the maximum key in the tree
template <class T>
T BinarySearchTree<T>::tree_max(treenode<T> * p){
    if(p != NULL){
        if(p->right==NULL)
            return p->data;
        else
            return tree_max(p->right);
    }
    /**
     * added return case for all paths
     * */
    else
    {
        return NULL;
    }
}

template <class T>
T BinarySearchTree<T>::min(){
   return tree_min(root);
}

//finds and returns the minimum key in the tree
template <class T>
T BinarySearchTree<T>::tree_min(treenode<T> * p){
    if(p != NULL){
        if(p->left==NULL)
            return p->data;
        else
            return tree_min(p->left);
    }
    /**
     * added return case for all paths
     * */
    else
    {
        return NULL;
    }
}

template <class T>
bool BinarySearchTree<T>::search(T& item){
   return tree_search(root, item);
}

//searches for the item in the entire tree
//returns true of tree contains the key
//returns false if tree doesn't contain the key
template <class T>
bool BinarySearchTree<T>::tree_search(treenode<T> * p, T& item){
    if(p == NULL)
        return false;
    else if(item<p->data)
        return tree_search(p->left, item);
    else if(item>p->data)
        return tree_search(p->right, item);
    else //a match is found item== p->data
        return true; 
}

//public function to initiate recursive call for remove operation
template <class T>
void BinarySearchTree<T>::remove(T& item){
    tree_remove(root, item);
}

//removes the item from the tree
//handles five cases:
//Case1: delete leaf node
//Case2: delete node with two children
//Case3: delete node with one left child
//Case4: delete node with one right child
//Case5: item is not found
template <class T>
void BinarySearchTree<T>::tree_remove(treenode<T> *& p, T& item){
    if(p == NULL)   //item not found
        return; 
    else if(item<p->data)
        tree_remove(p->left, item);
    else if(item>p->data)
        tree_remove(p->right, item);
    else {//item found
        if((p->left==NULL) && (p->right==NULL)){  //Case1: delete leaf node
            delete p;
            p = NULL;
        }else if ((p->left!=NULL) && (p->right!=NULL)){ //Case2: delete node with two children
            T max = tree_max(p->left);
            p->data = max;
            tree_remove(p->left, max);
        }else {
            treenode<T>* old = p;
            if(p->left!=NULL){//Case3: delete node with one left child
                p = p->left;
            }else if(p->right!=NULL){//Case4: delete node with one right child
                p = p->right;
            }
            delete old;

        }

    }

}


//delete each treenode created to build the tree
//it traverses the tree using post-order
template <class T>
void BinarySearchTree<T>::destroy(treenode<T>*& p){
    if(p != NULL){
        destroy(p->left);
        destroy(p->right);
        delete p;
        p = NULL;

    }
}

//destructor for Binary Search Tree
//destroys the tree and deallocates the
//dynamically allocated memory for each tree node
template <class T>
BinarySearchTree<T>::~BinarySearchTree(){
    destroy(root);
}

#endif //end of Binary Search Tree header file