#ifndef GRAPH_H
#define GRAPH_H

class Graph {
public:
    Graph(int vertices);
    ~Graph();
    void addEdge(int u, int v, int weight);
    void primMST();  // Must print MST edges and total weight

private:
    int** adjMatrix;
    int numVertices;
};

#endif