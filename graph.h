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

//Random graph structure
typedef struct graphR {
	int num_v;
    edge* edges;
    vertex* vertices;
} graphE;

//Euclidean graph structure
typedef struct graphE{
	double ws[num_v];
    double xs[num_v];
    double ys[num_v];
    double zs[num_v];
} graphG;

//graph structure declaration and initialization 
typedef struct union graph {
    graphE R;
    graphG E;
} graph;

