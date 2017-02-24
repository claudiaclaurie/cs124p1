#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define RANDOM 0
#define EUCLIDEAN 1

//is there a better data type???
//vertex structure declaration and initialization 
typedef unsigned int vertex;

//edge structure declaration and initialization 
typedef struct edge {
    vertex* va, vb;
    float weight;
} edge;

//graph structure declaration and initialization 
typedef struct graph {
    int num_v, num_e;
    edge* edges;
    vertex* vertices;
} graph;

