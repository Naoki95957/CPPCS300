#include <iostream>
#include "BinaryHeap.h"

using namespace std;

int main(){
    BinaryHeap<int> heap;
    int input;
    cout<<"Enter a number:";
    cin>>input;
    do{
        heap.insert(input);
        cout<<"Enter a number:";
        cin>>input;
    }while(input!=-1);

    cout<<"Min:"<<heap.getMin()<<endl;
    cout<<heap;
    cout<<"---------"<<"\n";
    heap.deleteMin();
    cout<<"Min:"<<heap.getMin()<<endl;
    cout<<heap;
    cout<<"---------"<<"\n";
    heap.deleteMin();
    cout<<"Min:"<<heap.getMin()<<endl;
    cout<<heap;
    cout<<"---------"<<"\n";
    heap.deleteMin();
    cout<<"Min:"<<heap.getMin()<<endl;
    cout<<heap;
    cout<<"---------"<<"\n";
    heap.deleteMin();
    cout<<"Min:"<<heap.getMin()<<endl;
    cout<<heap;
    cout<<"---------"<<"\n";
    heap.deleteMin();
    cout<<"Min:"<<heap.getMin()<<endl;
    cout<<heap;
    cout<<"---------"<<"\n";
}