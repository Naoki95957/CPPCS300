#include <iostream>
#include <cstdlib>
#include "BinarySearchTree.h"
// #include "Contact.h"
using namespace std;

int main(){

    auto test = []()
    {
        std::cout << "Hi there" << std::endl;
        return true;
    };
    test() || test();

    BinarySearchTree<int> tree;
    for(int i=0;i<20;i++)
    {
        int j = rand() % 100;
        tree.insert(j);
    }

    tree.printInOrder();
    std::cout << std::endl;
    
    std::cout << "Is BST?\n";
    std::cout << tree.isBST() << "\n";
    
    std::cout << "Is BST2?\n";
    std::cout << tree.isBST2() << "\n";


    return 0;
}
