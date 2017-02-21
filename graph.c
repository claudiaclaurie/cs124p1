#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

////////Union Operation Code

struct node {
  struct node *prev;
  int id;
  int rank;
};

node *makeset(int x)
{
  node *new = (node *) malloc(sizeof(node));
  new->id = x;
  new->prev = new;
  new->rank = 0;
    
  return new;
}

node *find(node *x)
{
  if (x != x->prev)
    {
      //path compression - otherwise, return find(x->prev)
      x->prev = find(x->prev);
      return x->prev;
    }
  return x;
}

void link(node *x, node *y)
{
  if (x->rank > y->rank)
    {
      link(y,x);
      return;
    }
  if (x->rank == y->rank)
    y->rank++;
  x->prev = y;
}

void mst_union(node *x, node *y)
{
  link(find(x),find(y));
}
