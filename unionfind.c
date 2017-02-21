
//Disjoint Set (Union-Find)
//Data structure to maintain a collection of disjoint sets 
struct set {
  struct set *prev;
  int id;
  int rank;
};

//Create a new set containting the single element x 
node *makeset(int x)
{
  node *new = (set *) malloc(sizeof(set));
  new->id = x;
  new->prev = new;
  // For Union by Rank, the rank of element x is set to 0 (only updated by link)
  new->rank = 0;
    
  return new;
}

//return the name of the set containing the element x 
node *find(set *x)
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
