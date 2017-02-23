#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "graph.h"

//randomly generate graph coordinates S

//calculate distances 

//generate graph with given parameters 

graph* createGraph(int num_v, int num_e){
    struct graph* g = malloc(sizeof(graph));
    g->num_v = num_v; //v is the number of vertices 
    g->num_e = num_e; //e is the number of edges 
    g->edges = malloc(sizeof(edge) * num_e); 
    g->vertices = NULL; 
    return g;

}

//set coordinates? 

//generates random number from 0 to 1 
double randnum(void) {
    return (double) rand() / (double) ((unsigned) RAND_MAX + 1);


//calculates euclidian distance with int d as the dimensionality 
double getdist(vertex a, vertex b, int d){ 
    double result =0;
    switch (d){
        case 2: {
            result = sqrt(pow(a.coordinates[0] - b.coordinates[0]),2) 
            + pow((a.coordinates[1] - b.coordinates[1]),2);
            break;
        }
        case 3: {
            result = sqrt(pow((a.coordinates[0] - b.coordinates[0]),2) 
            + pow((a.coordinates[1] - b.coordinates[1]),2)+ pow((a.coordinates[2] - b.coordinates[2]), 2)) ;
            break;
        }
        case 4: {
            result = sqrt( pow((a.coordinates[0] - b.coordinates[0]), 2) + pow((a.coordinates[1] - b.coordinates[1]), 2) 
            + pow((a.coordinates[2] - b.coordinates[2]), 2) + pow((a.coordinates[3] - b.coordinates[3]), 2) );
            break;
        }
    }
    return result;
}

// calculate weights?
    

// graph generator 
graph* randomGraph(int num_v, int num_d, int mode){
    //random seed generator   
    srand(time(NULL));
    if(mode == RANDOM){

    }
    else if (mode == EUCLIDEAN){
        double ws = [num_v];
        double xs = [num_v];
        double ys = [num_v];
        double zs = [num_v];
        
        for(int v = 0; v++; v < num_v){
            ws[v] = rand() % RAND_MAX;
            xs[v] = rand() % RAND_MAX;
            if(num_d == 3)
                ys[v] = rand() % RAND_MAX;
            if(num_d == 4)
                zs[v] = rand() % RAND_MAX;
        }
    }

}


int main(void){
    for(int n = pow(2,7); n = n*2; n<=pow(2, 17)){
        for(int num_d = 2; num_d++; num_d<=4){
            graph* g = randomGraph(int num_v, int num_d, int mode)
        }
    }
}


