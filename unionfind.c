#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "unionfind.h"
//Disjoint Set (Union-Find)
//Data structure to maintain a collection of disjoint sets 
struct set {
  struct set *prev;
  int parent;
  int rank;
};

//Create a new set containting the single element x 
set *makeset(int x)
{
  set *new = (set *) malloc(sizeof(set));
  new->parent = x;
  new->prev = new;
  // For Union by Rank, the rank of element x is set to 0 (only updated by link)
  new->rank = 0;
    
  return new;
}

//return the name of the set containing the element x 
set *find(set *x)
{
  if (x != x->prev)
    {
      // Once we find some element, adjust its parent pointer so it points directly to root 
      // Path compression 
      x->prev = find(x->prev);
      return x->prev;
    }
  return x;
}

//changes the parent pointer of x and makes it point to y, returning the root of the now composite tree y 
//keep tree depth smal l
void link(set *x, set *y)
{
   //rank for Union by Rank heuristic is updated here 
   //if x, y have the same rank, parent pointer of x to be updated to point y and y is updated to r + 1 
  if (x->rank == y->rank)
    y->rank++;
    x->prev = y;
  //parent pointer of smaller rank is updated to point to element with larger rank 
  if (x->rank > y->rank)
    {
      link(y,x);
      return;
    }

 
}
//replace two sets containing x and y by their union 
void mst_union(set *x, set *y)
{
  link(find(x),find(y));
}


int main(int argc, char **argv)
  {
  set *a = makeset(0);
  set *b = makeset(1);
  set *c = makeset(2);
    
  mst_union(b,a);
  mst_union(b,c);
    
  printf("%d, %d\n",find(a)->id, find(a)->rank);
  printf("%d, %d\n",find(b)->id, find(b)->rank);
    
  return 1;
  }