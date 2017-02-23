//Randmst 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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

    /* For timing caluclations
	struct timeval t0;
    struct timeval t1;
    gettimeofday(&t0, 0);
    gettimeofday(&t1, 0);
    long elapsed = (t1.tv_sec - t0.tv_sec) * 1000000 + t1.tv_usec - t0.tv_usec;
    printf("Operation took %ld microseconds\n", elapsed);
    */
}
