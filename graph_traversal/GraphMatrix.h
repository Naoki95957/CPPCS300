#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

#include <iostream>
#include "Graph.h"
#include "ArrayStack.h"
#include "ArrayQueue.h"
using namespace std;


class GraphMatrix:public Graph{
    //adjacency matrix is array of pointers, each array element is another array. matrix[n][n]
    bool** adjMatrix;
    //size of the matrix
    int vertex;
    //boolean array to keep track of visited vertices
    bool *visited = nullptr;

    public:
        //consturact graph object using adjacency matrix
        //initialize cells to false to make the initial graph disconnected
        GraphMatrix(int _vertex){
            vertex = _vertex;
            adjMatrix = new bool*[vertex];  //create an array of arrays

            for(int i=0;i<vertex;i++){      
                adjMatrix[i] = new bool[vertex]; 
                for(int j=0;j<vertex;j++){
                    adjMatrix[i][j] = false;    //i is row, j is column
                }
            }
        }

        //adds an edge between v and w vertices by turning on matrix[v][w] cell on
        void addEdge(int v, int w){
            if((v>=0 && v< vertex) && (w>=0 && w<vertex)){
                adjMatrix[v][w] = true;
                adjMatrix[w][v] = true;
            }
        }

        //removes the edge between v and w vertices
        //turns off the cell matrix[v][w]
        void removeEdge(int v, int w){
            if((v>=0 && v< vertex) && (w>=0 && w<vertex)){
                adjMatrix[v][w] = false;
                adjMatrix[w][v] = false;
            }
        }

        //checks if matrix[v][w] is on meaning that there is an edge between given vertices
        bool isEdge(int v, int w){
            if((v>=0 && v< vertex) && (w>=0 && w<vertex)){
                return adjMatrix[v][w];
            }
            return false;
        }

        //prints the graph represented by matrix
        void display(){
            cout << "X|";
            for(int x = 0; x < vertex; ++x)
            {
                cout << x << " ";
            }
            cout << "\n";

            for(int y = 0; y < vertex * 2 + 1; ++y)
            {
                cout << "-";
            }
            cout << "\n";
            for(int i=0;i<vertex;i++){
                cout<<i<<"|";               //row by row, i represents row
                for(int j=0;j<vertex;j++){
                    cout<<adjMatrix[i][j]<<" ";     //prints the cell info
                }
                cout<<endl;
            }
        }

        //release visited nodes
        void initialize(){
            if(visited == nullptr)
            {
                visited = new bool[vertex];
            }
            for(int i=0;i<vertex;i++)
                visited[i] = false;
        }
        void dfsr(int s, int target = -1)
        {
            initialize();
            dfsr_r(s, target);
        }

        bool dfsr_r(int s, int target = -1)
        {
            for(int y = 0; y < vertex; ++y)
            {
                if(adjMatrix[s][y] && !visited[y])
                {
                    visited[y] = true;
                    if(y == target)
                    {
                        return true;
                    }
                    else
                    {
                        bool var = dfsr_r(y, target);
                        if(var)
                        {
                            cout << y << " ";
                        }
                        return var;
                    }
                }
            }
            return false;
        }
        //initial node
        void dfs(int s, int target = -1)
        {
            initialize();
            ArrayStack<int> stack(vertex);//sq bc worst case scenario

            visited[s] = true;
            stack.push(s);

            while(!stack.isEmpty())
            {
                int x = stack.top();
                stack.pop();
                
                for(int y = 0; y < vertex; ++y)
                {
                    if(adjMatrix[x][y])
                    {
                        if(!visited[y]){
                            stack.push(y);
                            visited[y] = true;
                        }
                    }
                }
                cout << x << " ";
                if(target != -1)
                {
                    if(x == target)
                    {
                        break;
                    }
                }
            }
        }

        //breadth-first search traversal
        void bfs(int s){
            initialize();
            ArrayQueue<int> queue(vertex);

            visited[s] = true;
            queue.enqueue(s);

            while(!queue.isEmpty()){
                int v = queue.qfront();
                queue.dequeue();

                for(int w=0;w<vertex;w++){
                    if(adjMatrix[v][w]){
                        if(!visited[w]){
                            queue.enqueue(w);
                            visited[w] = true;
                        }
                    }
                }
                cout<<v<<" ";

            }

        }

        ~GraphMatrix(){
            for(int i=0;i<vertex;i++){
                delete[] adjMatrix[i];
            }
            delete[] adjMatrix;
        }

};

#endif