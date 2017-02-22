#include <stdio.h>
#include <stdlib.h>

//object that gets placed in min-heap
typedef struct heapNode {
    int id; // id references corresponding vertex in graph 
    int distance;
    int prev; //prev vertex in graph 
} heapNode;

typedef struct minHeap {
    int c; //number of children 
    int size;
    heapNode* array;
} minHeap;

//initialize heap
minHeap* initHeap();

//makes this a min heap
void minHeapify(int root, minHeap* heap);

//eturns min heap 
heapNode extractMin(minHeap* heap);

//put object into heap
void insert(heapNode vertex, minHeap* heap);