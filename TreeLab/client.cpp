#include <iostream>
#include "Lists/LinkedList.hpp"

struct treenode
{
    int d = NULL;
    treenode * l = nullptr;
    treenode * r = nullptr;
    treenode(int d)
    :d(d)
    {}
};

int countNodesIterative(treenode * root)
{
    LinkedList<treenode *> list;
    treenode * temp = root;
    int count = 0;

    if(!(temp != nullptr || temp != NULL))
    {
        return 0;
    }
    else while(temp != nullptr || temp != NULL)
    {
        if(temp->l != nullptr)
        {
            list.insertLast(temp->l);
        }
        if(temp->r != nullptr)
        {
            list.insertLast(temp->r);
        }
        temp = list.get(0);
        list.remove(0);
        ++count;
    }
    return count;
}

int countNodesRecursive(treenode * root)
{
    int combine = 0;
    if(root == NULL || root == nullptr)
    {   
        return 0;
    }
    else
    {
        ++combine;
        combine += countNodesRecursive(root->l);
        combine += countNodesRecursive(root->r);
    }
    return combine;
}

int countInternalNodes(treenode * root)
{
    if(root == NULL || root == nullptr)//base case
    {
        return 0;
    }
    else if((root->l != NULL || root->l != nullptr) || (root->r != NULL || root->r != nullptr))//internals
    {
        return 1 + countInternalNodes(root->l) + countInternalNodes(root->r);
    }
    else //these are the leaves
    {
        return 0;
    }
}

int countLeaves(treenode * root)
{
    return countNodesIterative(root) - countInternalNodes(root);
}

int main()
{
    treenode * root;
    root = new treenode(1);
    root->l = new treenode(2);
    root->l->l = new treenode(4);
    root->l->r = new treenode(5);
    root->r = new treenode(3);
    root->r->l = new treenode(6);
    root->r->l->l = new treenode(7);

    int count = countInternalNodes(root);
    std::cout << count << std::endl;
    
    count = countLeaves(root);
    std::cout << count << std::endl;

    return 0;
}