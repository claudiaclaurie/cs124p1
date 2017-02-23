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
    


/*
// Generates a random float from 0 to 1
float randFloat() {
    return (float) rand() / (float) RAND_MAX;
}
// Calculates distance between two points start, end with dimensionality d
float distance(int d, float start[d], float end[d]) {
    float sum = 0;

    for (int i = 0; i < d; i++) {
        sum += square(start[i] - end[i]);
    }

    return sqrt(sum);
}

// Calculates square of number n
float square(float n) {
    return n * n;
}
*/

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


