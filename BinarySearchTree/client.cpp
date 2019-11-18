#include <iostream>
#include "BinarySearchTree.h"
// #include "Contact.h"

using namespace std;

int main(){
    BinarySearchTree<int> tree;
    for(int i=0;i<5;i++){
        tree.insert(i);
    }
    tree.printInOrder();
    cout<<endl;
    tree.printPostOrder();
    cout<<endl;
    tree.printPreOrder();
    cout<<endl;
    cout<<tree.height()<<endl;
    cout<<tree.max()<<endl;
    cout<<tree.min()<<endl;
    int x = 4;
    cout<< (tree.search(x) ? "Found x" : "Couldn't find x") <<endl;
    tree.remove(x);
    cout<< (tree.search(x) ? "Found x" : "Couldn't find x") <<endl;

    return 0;
}