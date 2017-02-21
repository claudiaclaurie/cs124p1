#ifndef unionfind
#define unionfind

typedef struct set set;

set *makeset(int x);
set *find(set *n);
void mst_union(set *x, set *y);

#endif