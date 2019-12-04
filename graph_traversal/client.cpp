#include "GraphMatrix.h"
#include <iostream>

using namespace std;

int main(){
    GraphMatrix graph(36);

    graph.addEdge(12, 6);
    graph.addEdge(6, 0);
    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 8);
    graph.addEdge(1, 7);
    graph.addEdge(7, 13);
    graph.addEdge(13, 14);
    graph.addEdge(14, 15);
    graph.addEdge(15, 9);
    graph.addEdge(9, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 10);
    graph.addEdge(10, 16);
    graph.addEdge(16, 22);
    graph.addEdge(22, 23);
    graph.addEdge(23, 17);
    graph.addEdge(17, 11);
    graph.addEdge(11, 5);
    graph.addEdge(23, 29);
    graph.addEdge(29, 35);
    graph.addEdge(34, 35);
    graph.addEdge(34, 28);
    graph.addEdge(12, 18);
    graph.addEdge(18, 19);
    graph.addEdge(19, 20);
    graph.addEdge(20, 26);
    graph.addEdge(26, 27);
    graph.addEdge(27, 21);
    graph.addEdge(27, 33);
    graph.addEdge(33, 32);
    graph.addEdge(32, 31);
    graph.addEdge(31, 30);
    graph.addEdge(30, 24);
    graph.addEdge(24, 25);
    
    
    graph.display();
    cout << "\n";
    cout<<"BFS:";
    graph.bfs(12);
    cout << "\n" << "DFS:";
    graph.dfs(12, 23);
    
    cout << "\n" << "DFSR:";
    graph.dfsr(12, 23);
    cout<<endl;
 
}



