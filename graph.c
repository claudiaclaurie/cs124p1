#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <time.h>

typedef struct Vertex
{
	int coords[4];
};

//a weighted edge in a graph
typedef struct Edge
{
    int source, dest, weight;
};
//Weightd graph structure
typedef struct Graph
{
        // V: Number of vertices, E: Number of edges, D: Number of dimensions
        int V, E, D;
 
        // graph is represented as an array of edges. 
        // graph is undirected, so edges are bidirectional
        struct Edge* edge;
};
// Creates a graph with V vertices and E edges and dimenions D
struct Graph* createGraph(int V, int E, int D)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->D = D;
 
    graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));
 
    return graph;
}

