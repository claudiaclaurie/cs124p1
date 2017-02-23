#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define RANDOM 0
#define EUCLIDEAN 1

//edge structure declaration and initialization 
typedef struct edge {
    int start, end;
    float weight;
} edge;


//vertex structure declaration and initialization 
typedef struct vertex {
    double* coordinates;
} vertex;

//graph structure declaration and initialization 
typedef struct graph {
    int num_v, num_e;
    edge* edges;
    vertex* vertices;
} graph;

