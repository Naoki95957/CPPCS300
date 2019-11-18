/**
 *  Naoki Lucas
 *  Nov. 17th 2019
 *  Binary Search Tree 
 * */

#include <algorithm>
#include <iostream>

#ifndef BinaryST_H
#define BinaryST_H
template <typename T>
struct TreeNode{
    T data;
    TreeNode * left;
    TreeNode * right;
};


template <typename T>
class BinarySearchTree
{
    private:
        TreeNode<T> * root;
        
        //recursive helper
        void insert_helper(TreeNode<T> *& root, T val)
        {
            if(root == NULL)
            {
                TreeNode<T> * newNode = new TreeNode<T>();
                newNode->data = val;
                newNode->left = NULL;
                newNode->right = NULL;
                root = newNode;
            }
            else if(val > root->data)
            {
                insert_helper(root->right, val);
            }
            else if(val < root->data)
            {
                insert_helper(root->left, val);
            }
        }

        //recursive helper
        bool search_helper(TreeNode<T> * root, T& val)
        {
            if(root == NULL)
            {
                return false;
            }
            else if(val < root->data)
            {
                return search_helper(root->left, val);
            }
            else if(val > root->data)
            {
                return search_helper(root->right, val);
            }
            else
            {
                return val == root->data;
            }
        }

        //recursive helper
        void remove_helper(TreeNode<T> * root, T& val)
        {
            if(root == NULL)
            {
                return;
            }
            else if(val > root->data)
            {
                remove_helper(root->right, val);
            }
            else if(val < root->data)
            {
                remove_helper(root->left, val);
            }
            else
            {
                //no child
                if(root->right == NULL && root->left == NULL)
                {
                    delete root;
                    root = NULL;
                    return;
                }
                //2 children
                else if(root->right != NULL && root->left != NULL)
                {
                    //find max of left subtree
                    T max = max_helper(root->left);
                    //set the subtree root as a copy of max
                    root->data = max;
                    //delete the original
                    remove_helper(root->left, max);
                }
                //1 child
                else
                {
                    TreeNode<T> * toDel = root;
                    if(root->left == NULL)
                    {
                        root = root->right;
                    }
                    else //if(root->right == NULL)//would always turn up true if all others failed 
                    {
                        root = root->left;
                    }
                    delete toDel;
                }   
            }
        }

        //recursive helper
        T max_helper(TreeNode<T> * root)
        {
            if(root == NULL)
            {
                return NULL;
            }
            else
            {
                if(root->right == NULL)
                {
                    return root->data;
                }
                else
                {
                    return max_helper(root->right);
                }
            }
        }

        //recursive helper
        T min_helper(TreeNode<T> * root)
        {
            if(root == NULL)
            {
                return NULL;
            }
            else
            {
                if(root->left == NULL)
                {
                    return root->data;
                }
                else
                {
                    return min_helper(root->left);
                }
            }
        }

        //recursive helper
        int height_helper(TreeNode<T> * root)
        {
            if(root == NULL)
            {
                return 0;
            }
            else
            {
                return 1 + std::max(height_helper(root->left), height_helper(root->right));
            }
        }
        
        //recursive helper
        void printInOrder_helper(TreeNode<T> * root)
        {
            if(root != NULL){
                tree_printInOrder(root->left);
                std::cout<<root->data<<" ";
                tree_printInOrder(root->right);
            }
        }

        //recursive helper
        void printPreOrder_helper(TreeNode<T> * root)
        {
            if(root != NULL){
                std::cout<<root->data<<" ";
                tree_printInOrder(root->left);
                tree_printInOrder(root->right);
            }
        }

        //recursive helper
        void printPostOrder_helper(TreeNode<T> * root)
        {
            if(root != NULL){
                tree_printInOrder(root->left);
                tree_printInOrder(root->right);
                std::cout<<root->data<<" ";
            }
        }

        //recursive helper
        void destroyer(TreeNode<T> * root)
        {
            if(root != NULL)
            {
                destroyer(root->left);
                destroyer(root->right);
                delete root;
                root = NULL;
            }
        }

    public:
        //Constructor: Default root is NULL
        BinarySearchTree()
        {
            root = NULL;
        }

        //creates a new node if value isn't already in the tree
        void insert(T val)
        {
            insert_helper(root, val);
        }
        
        //searches for a value, and returns true if a match is found
        bool search(T& val)
        {
            return search_helper(root, val);
        }

        
        void remove(T& val);
        
        //Finds the greatest value stored in the tree
        //if not found, it will return NULL
        T max()
        {
            return max_helper(root);
        }
        //Finds the least-greatest value stored in the tree
        //if not found, it will return NULL
        T min()
        {
            return min_helper(root);
        }

        //Returns the overall height of the tree
        //
        //Reminder: height is the count in the path, not the nodes.
        //if no path is present (IE 1 or no nodes), returns 0
        int height()
        {
            int toReturn = height_helper(root) - 1;
            return (toReturn < 1 ? 0 : toReturn);
        }

        //prints left, data, right to terminal
        void printInOrder()
        {
            printInOrder_helper(root);
        }

        //prints data, left, right to terminal
        void printPreOrder()
        {
            printPreOrder_helper(root);
        }

        //prints left, right, data, to terminal
        void printPostOrder()
        {
            printPostOrder_helper(root);
        }

        //destructor: deletes stuff
        ~BinarySearchTree()
        {
            destroyer(root);
        }
};
#endif