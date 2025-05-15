#include "graph.h"
#include "heap.h"
#include <iostream>
#include <climits>

using namespace std;

// Constructor
Graph::Graph(int vertices) : numVertices(vertices) {

    adjMatrix = new int*[numVertices];



    for (int i = 0; i < numVertices; ++i) {
        adjMatrix[i] = new int[numVertices];

        for (int j = 0; j < numVertices; ++j) {
            adjMatrix[i][j] = 0;
        }
    }

}

// Destructor
Graph::~Graph() {

    for (int i = 0; i < numVertices; ++i) {

        delete[] adjMatrix[i];
    }

    delete[] adjMatrix;
}


void Graph::addEdge(int u, int v, int weight) {
    if (u < 0 || v < 0 || u >= numVertices || v >= numVertices) { //checks for "negative" vertices or out of bounds vertices
        return;
    }

    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}


void Graph::primMST() {

    int* parent = new int[numVertices];

    //unvisited
    MinHeap minHeap(numVertices);

    for (int v = 0; v < numVertices; ++v) {

        parent[v] = -1;
        minHeap.insert(v, INT_MAX);
    }

   minHeap.decreaseKey(0, 0);
    while (!minHeap.isEmpty()) {
        int u = minHeap.extractMin();

        //checks for connection to u
        for (int v = 0; v < numVertices; ++v) {
            int weight = adjMatrix[u][v];

            if (weight && minHeap.isInMinHeap(v) && weight < minHeap.getKey(v)) {
                parent[v] = u;
                minHeap.decreaseKey(v, weight);
            }
        }
    }

    int totalWeight = 0;
    cout << "Edges and Weights:" << endl;
    for (int i = 1; i < numVertices; ++i) {


        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << "    Weight: " << adjMatrix[i][parent[i]] << endl;
            totalWeight += adjMatrix[i][parent[i]];
        }
    }
    cout << "Total weight of MST: " << totalWeight << endl;

    delete[] parent;
}
