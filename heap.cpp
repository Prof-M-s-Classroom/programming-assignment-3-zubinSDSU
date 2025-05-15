#include "heap.h"
#include <climits>
using namespace std;
#include <algorithm>

//constructor
MinHeap::MinHeap(int capacity) : capacity(capacity), size(0) {

    heapArray = new int[capacity]; //vertex heap
    keyArray = new int[capacity]; //weights of each vertex
    position = new int[capacity]; //index of each vertex in heap

    for (int i = 0; i < capacity; i++) {
          keyArray[i] = INT_MAX;
          position[i] = -1;
    }

  }

  //deconstructor
  MinHeap::~MinHeap() {

    delete[] heapArray;
    delete[] keyArray;
    delete[] position;

  }

  void MinHeap::insert(int vertex, int key) {
        heapArray[size] = vertex;
        keyArray[vertex] = key;
        position[vertex] = size;
        int i = size++;


        while(i && keyArray[heapArray[i]] < keyArray[heapArray[(i-1) / 2]]) {

          swap(position[heapArray[i]], position[heapArray[(i-1) / 2]]);
          swap(heapArray[i], heapArray[(i-1) / 2]);
          i = i / 2;


          }

  }

  int MinHeap::extractMin() {
    if(size == 0) {
      return -1;
      }


    int root = heapArray[0];
    heapArray[0] = heapArray[size - 1];
    position[heapArray[0]] = 0;
    size--;
    minHeapify(0);

  return root;
  }

  void MinHeap::decreaseKey(int vertex, int newKey) {
    int i = position[vertex];
    keyArray[vertex] = newKey;

    while (i && keyArray[heapArray[i]] < keyArray[heapArray[(i - 1) / 2]]) {

      swap(position[heapArray[i]], position[heapArray[(i - 1) / 2]]);
      swap(heapArray[i], heapArray[(i - 1) / 2]);

      i = (i - 1) / 2;
    }
  }

bool MinHeap::isInMinHeap(int vertex) {
  return position[vertex] < size;
}

bool MinHeap::isEmpty() {
  return size == 0;
}

void MinHeap::minHeapify(int idx) {
  int smallest = idx;
  int left = 2 * idx + 1, right = 2 * idx + 2;

  if (left < size && keyArray[heapArray[left]] < keyArray[heapArray[smallest]])
    smallest = left;

  if (right < size && keyArray[heapArray[right]] < keyArray[heapArray[smallest]])
    smallest = right;

  if (smallest != idx) {
    swap(position[heapArray[smallest]], position[heapArray[idx]]);
    swap(heapArray[smallest], heapArray[idx]);
    minHeapify(smallest);
  }

}

//needed for insert, extract, and isMinHeap
void MinHeap::swap(int& a, int& b) {

  int temp = a;
  a = b;
  b = temp;
}

//needed for primMST
int MinHeap::getKey(int idx) {

  return keyArray[idx];
}



