#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "graph.h"

#define infinity 9999
#define MAX 20

int G[MAX][MAX],spanning[MAX][MAX],n;
int prims();
int prims() {
	int cost[MAX][MAX];
    int u,v,min_distance,distance[MAX],from[MAX];
    int visited[MAX],num_edges,i,minimumCost,j;
 
   /* For first smallest edge */

    for(i=0; i<n; i++)
        for(j=0; j<n ;j++)
        {
            if(G[i][j]==0)
                cost[i][j]=infinity;
            else
                cost[i][j]=G[i][j];
                spanning[i][j]=0;
        }
 
       //initialise visited[],distance[],from[]
    distance[0]=0;
    visited[0]=1;
    
    for(i=1; i<n; i++)
    {
        distance[i]=cost[0][i];
        from[i]=0;
        visited[i]=0;
    }

// cost of the spanning tree and the number of edges to be added 
    minimumCost = 0;
    num_edges = n-1; 

  while(num_edges > 0)
    {
        //find the vertex at minimum distance from the tree
        min_distance = infinity;
        for(i = 1; i < n; i++)
            if(visited[i] == 0 && distance[i] < min_distance)
            {
                v=i;
                min_distance = distance[i];
            }
            
        u =from[v];
        
        //insert the edge in spanning tree
        spanning[u][v] = distance[v];
        spanning[v][u] = distance[v];
        num_edges--;
        visited[v]=1;
        
        //updated the distance[] array
        for(i=1; i<n; i++)
            if(visited[i] == 0 && cost[i][v] < distance[i]){
            	distance[i]=cost[i][v];
                from[i]=v;	
            }
            
        
        minimumCost = minimumCost+cost[u][v];
    }
    
    return(minimumCost);
}
   
int main()
{
    int total_cost;
    
    total_cost=prims();
    
    printf("\n\nTotal cost of spanning tree=%d",total_cost);
    return 0;
}
 

  
  