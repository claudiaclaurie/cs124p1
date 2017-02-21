#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//main function that takes the correct inputs 
int main (int argc, char **argv) {
  if (argc != 5) {
    printf("wrong number of arguments supplied \n");
    return 0;
  }

  int numpoints = strtol(argv[2], NULL, 10);
  int numtrials = strtol(argv[3], NULL, 10);
  int dimension = strtol(argv[4], NULL, 10);
  printf("numpoints = %d, numtrials = %d, dimension = %d \n", numpoints, numtrials, dimension);

  if(dimension == 1 || dimension > 4){
        printf("invalid dimension input\n");
        return 0;
    }
  //random seed generator   
  srand(time(NULL));


    
////////Graph Initialization

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

