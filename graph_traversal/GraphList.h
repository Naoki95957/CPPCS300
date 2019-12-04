#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H

#include <iostream>
#include "LinkedList.h"
#include "Graph.h"
#include "ArrayQueue.h"

using namespace std;


class GraphList:public Graph{
    LinkedList<int>* adjList;   //adjacency list, an array of LinkedList objects
    int vertex;                 //number of vertices in the graph
    bool *visited;              //a boolean array to keep track of visited nodes
    public:
        //constructs a graph with an array of LinkedList objects.
        GraphList(int _vertex){
            vertex = _vertex;
            adjList = new LinkedList<int>[vertex];  //create matrix [vertex][vertext]

        }

        //adds w to the adjacency list of v
        //adds v to the adjacency list of w
        void addEdge(int v, int w){
            if((v>=0 && v< vertex) && (w>=0 && w<vertex)){
                adjList[v].insert_first(w);
                adjList[w].insert_first(v);
            }
        }

        //remove w from the adjacency list of v
        //remove v from the adjacency list of w
        void removeEdge(int v, int w){
            if((v>=0 && v< vertex) && (w>=0 && w<vertex)){
                adjList[v].remove(w);
                adjList[w].remove(v);
            }
        }
        //checks if w is in the adjacency list of v 
        bool isEdge(int v, int w){
            if((v>=0 && v< vertex) && (w>=0 && w<vertex)){
                return adjList[v].search(w);
            }
            return false;
        }

        //prints the graph
        void display(){
            for(int i=0;i<vertex;i++){
                cout<<i<<":";
                cout<<adjList[i];
            }
        }
        void initialize(){
            visited = new bool[vertex];
            for(int i=0;i<vertex;i++)
                visited[i] = false;
        }
        void bfs(int s){
            initialize();
            ArrayQueue<int> queue(vertex);

            visited[s] = true;
            queue.enqueue(s);

            while(!queue.isEmpty()){
                int v = queue.qfront();
                queue.dequeue();

                for(int w=0;w<vertex;w++){
                    if(adjList[v].search(w)){
                        if(!visited[w]){
                            queue.enqueue(w);
                            visited[w] = true;
                        }
                    }
                }
                cout<<v<<" ";

            }

        }


        //destroys the graph //array of linked list object
        ~GraphList(){
            delete[] adjList;
        }

};

#endif