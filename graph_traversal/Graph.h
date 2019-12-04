#ifndef GRAPH_H
#define GRAPH_H


class Graph{

    public:
        virtual void addEdge(int, int) = 0; //add an edge between two vertices
        virtual bool isEdge(int, int) = 0;  //checks if there is an edge between two vertices
        virtual void removeEdge(int, int) = 0;  //remove the edge between two vertices
        virtual void display() = 0;     //prints the graph
        virtual void bfs(int) = 0;      //traverses the graph using breadth-first search traversal

};

#endif