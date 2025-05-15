[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Zubin Kumar
130510000

## Description
My program uses Prim's algorithm to find the Minimum Spanning Tree. This basically means that we use an algorithm to find the path of least resistance to all nodes within a given graph. We use heap.cpp for methods within graph.cpp to keep track of visted nodes, position of nodes with an array index, and weights of edges. Graph starts at node 0, takes the path of least resistance, extractMin to remove it and keeps going until all nodes are visited. Using an adjacency matrix, we keep track of edges and paths. Additionally, we keep track of the total weight of the MST and the edges taken.     

## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis


| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | O(log V)        |
| Extract Min          | O(log V)        |
| Decrease Key         | O(log V)        |
| Prim’s MST Overall   | O(V^2)          |

_Explain why your MST implementation has the above runtime._
    Insert: We place it at the bottom of the heap (end of the array) and push it up to the top, which follows a logN structure (binary tree).
    Extract Min: To extract, we remove the root, move the last element to the root, and then use heapify to restructure to a heap. Removing and moving the root take O(1), but heapify Log V due to the binary tree structure.
    Decrease Key: Used when a path of less resistance if found to a vertex. Due to the binary tree nature of keyArray[], it will take a worst case of O(Log V) to push the new key value up the tree.
    Overall: Due to the nature of our adjacency matrix, which is a nested for loop, it runs O(V^2). First we loop over all extraded nodes, 'u', and then we check all possible neighbors, 'v', running O(V^2).
    
## Design Decisions:
    Implemented void swap() as a helper method for heap.cpp. This required me to add it to the heap.h header file under public methods. Additionally, made a getKey(int vertex) helper method in heap.cpp for graph.cpp. Key is a private variable for heap, and I needed it for primMST. 

## Test Case Description

------------------------
- Example input:
Graph g(5);
g.addEdge(0, 1, 2);
g.addEdge(0, 3, 6);
g.addEdge(1, 2, 3);
g.addEdge(1, 3, 8);
g.addEdge(1, 4, 5);
g.addEdge(2, 4, 7);
g.addEdge(3, 4, 9);

g.primMST();

- Output:
Edges and Weights:
0 - 1   Weight: 2
1 - 2   Weight: 3
0 - 3   Weight: 6
1 - 4   Weight: 5
Total weight of MST: 16

-----------------

- No edges:
  Graph g(4);
  g.primMST();

- Output:
  Edges and Weights:
  Total weight of MST: 0

-------------------------
- Disconnected:
  Graph g(4);
  g.addEdge(0, 1, 1);
  g.addEdge(2, 3, 2);
  g.primMST();

- Output:
  Edges and Weights:
  0 - 1   Weight: 1
  2 - 3   Weight: 2
  Total weight of MST: 3





