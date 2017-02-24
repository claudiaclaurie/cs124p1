#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "graph.h"

//randomly generate graph coordinates S

//calculate distances 

//generate RANDOM graph with given parameters 

graphR* createGraphR(int num_v){
    struct graphR* g = malloc(sizeof(graph));
    g->num_v = num_v; //v is the number of vertices
    //complete graph has v(v-1)/2 edges
    g->edges = malloc(sizeof(edge)* num_v*(num_v-1)/2); 
    g->vertices = NULL; 
    return g;

}

//generates random number from 0 to 1 
double randnum(void) {
    return (double) rand() / (double) ((unsigned) RAND_MAX + 1);
}


//calculates euclidian distance with int d as the dimensionality 
double getdist(vertex a, vertex b, int d){ 
    double result =0;
    switch (d){
        case 2: {
            result = sqrt(pow(a.coordinates[0] - b.coordinates[0],2)) 
            + pow((a.coordinates[1] - b.coordinates[1]),2);
            break;
        }
        case 3: {
            result = sqrt(pow(a.coordinates[0] - b.coordinates[0],2))
            + pow((a.coordinates[1] - b.coordinates[1]),2)+ pow(a.coordinates[2] - b.coordinates[2], 2) ;
            break;
        }
        case 4: {
            result = sqrt( pow(a.coordinates[0] - b.coordinates[0], 2) + pow((a.coordinates[1] - b.coordinates[1]), 2) 
            + pow((a.coordinates[2] - b.coordinates[2]), 2) + pow((a.coordinates[3] - b.coordinates[3]), 2) );
            break;
        }
    }
    return result;
}


// RANDOM graphR generator 
graphR* rGraphR(int num_v){
    //random seed generator   
    srand(time(NULL));
    graphR* G = createGraph(num_v);

    //connect all vertices to each other for complete graph
    int c, d;
    int edgecount = 0
    for(c=0; c++; c<num_v){
        //add each vertice to graph
        vertex va;
        G->vertices[c] = va;

        for(d=1; d++; d<num_v){
            float weight = randnum();
            vertex vb;

            //create edge, set weight and vertices
            edge e;
            e->weight = weight;
            e->va = *va;
            e->vb = *vb;

            //add edge to graph
            G->edges[edgecount] = e;
            edgecount++;
        }
    }
    return G;
}

// EUCLIDEAN graphE generator 
graphE* rGraphE(int num_v, int num_d){
    //random seed generator   
    srand(time(NULL));
    graphE g;

    double ws[num_v];
    double xs[num_v];
    double ys[num_v];
    double zs[num_v];
    
    int v;
    for(v = 0; v++; v < num_v){
        ws[v] = rand() % RAND_MAX;
        xs[v] = rand() % RAND_MAX;
        if(num_d == 3)
            ys[v] = rand() % RAND_MAX;
        if(num_d == 4)
            zs[v] = rand() % RAND_MAX;
    }

    g->ws = ws;
    g->xs = xs;
    g->ys = ys;
    g->zs = zs;

    return g;
}

graph* randomGraph(int num_v, int num_d, int mode){
    if(mode == RANDOM){

    }
    else if(mode == EUCLIDEAN){
        
    }
}

int main(void){
    int n;
    for(n = pow(2,7); n = n*2; n<=pow(2, 17)){
        int num_d;
        for(num_d = 2; num_d++; num_d<=4){
            //graph* g = randomGraph(num_v, num_d, mode)
        }
    }
}

