#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "graph.h"

#define infinity 9999
#define MAX 20

int G[MAX][MAX];
int spanningtree[MAX][MAX];
int n;
int prims();
int prims() {
	int cost[MAX][MAX];
	int u;
	int v;
	int min_distance;
	int distance[MAX];
	int from[MAX];
	int visited[MAX];
	int num_edges;
	int i, j;
	int minimumCost;

	//For the first smallest edge in the adjacency matrix...

	for (i = 0; i < n; i++)
		for (j = 0; j < n ; j++)
		{
			if (G[i][j] == 0)
				cost[i][j] = infinity;
			else
				cost[i][j] = G[i][j];
			spanningtree[i][j] = 0;
		}

	//initialise visited[],distance[],from[]
	//mark starting node as visited
	distance[0] = 0;
	visited[0] = 1;

	for (i = 1; i < n; i++)
	{
		distance[i] = cost[0][i];
		from[i] = 0;
		visited[i] = 0;		//mark all other nodes as unvisited
	}

// initialize cost of the spanning tree and the number of edges to be added
	minimumCost = 0;
	num_edges = n - 1;

	while (num_edges > 0)
	{
		//while there are edges, find the vertex at minimum distance from the tree
		min_distance = infinity;
		for (i = 1; i < n; i++) //do this until all nodes in the graph have been reached
			if (visited[i] == 0 && distance[i] < min_distance)
			{
				v = i;
				min_distance = distance[i];
			}

		u = from[v];

		//insert the edge in spanning tree
		spanningtree[u][v] = distance[v];
		spanningtree[v][u] = distance[v];
		num_edges--;
		visited[v] = 1;		//update visited

		//updated the distance[] array
		for (i = 1; i < n; i++)
			if (visited[i] == 0 && cost[i][v] < distance[i]) {
				distance[i] = cost[i][v];
				from[i] = v;
			}


		minimumCost = minimumCost + cost[u][v];
	}

	return (minimumCost);
}

int main()
{
	int total_cost;

	total_cost = prims();

	printf("\n\nTotal cost of spanning tree=%d", total_cost);
	return 0;
}



