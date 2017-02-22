#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//randomly generate graph coordinates 

//calculate distances 

//generate graph with given parameters and return MST of graph 

graph* createGraph(int num_v, int num_e){
    graph* g = malloc(sizeof(graph));
    g->num_v = num_v; //v is the number of vertices 
    g->num_e = num_e; //e is the number of edges 
    g->edges = malloc(sizeof(edge) * num_e); 
    g->vertices = NULL; 
    return g;


}

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



