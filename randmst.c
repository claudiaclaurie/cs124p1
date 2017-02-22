//Randmst 
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
}
