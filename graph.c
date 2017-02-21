#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

////////Graph Initialization

typedef struct Vertex
{
	int coords[4];
}Vertex;

//a weighted edge in a graph
typedef struct Edge
{
    int source, dest, weight;
}Edge;

//Weightd graph structure
typedef struct Graph
{
        // V: Number of vertices, E: Number of edges, D: Number of dimensions
        int V, E, D;
 
        // graph is represented as an array of edges. 
        // graph is undirected, so edges are bidirectional
        Edge* edge;
}Graph;

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

////////Union Operation Code

//a subset structure for union-find
typedef struct subset
{
    int parent;
    int rank;
}subset;

//Find a root with element k
int find(subset subsets[], int k)
{
    // find root with value k, path compress finding nodes to root
    if (subsets[k].parent != k)
        subsets[k].parent = find(subsets, subsets[k].parent);
 
    return subsets[k].parent;
}
