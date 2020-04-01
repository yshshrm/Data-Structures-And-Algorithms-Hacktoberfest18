#include <stdio.h>
#include <stdlib.h>
#define MAX 2000000

int min(int x, int y)
{
  if (x < y) return x;
  return y;
}

// array is the input array
// segtree is the segment tree array of size 2n-1
// left and right are pointers to the two ends of the array for recursion
// currentpos points to the current position in the segtree array to store the node in.

// we start building segtree recursively from top down. Therefore the last n elements are the actua elements, and the first element is the whole range.

void buildsegtree(int *array, int *segtree, int left, int right, int currentpos)
{
  // Case when we reach the leaf node, and e recursion ends.
  if (left == right)
  {
    segtree[currentpos] = array[left];
    return;
  }
  
  //finding the middle element to divide the segment tree.
  int middle = (left+right)/2;
  // Recursively calling the build function on each half
  // Current position becomes the position of child, which is 2n+1, 2n+2
  buildsegtree(array, segtree, left, middle, 2*currentpos+1);
  buildsegtree(array, segtree, middle+1, right,2*currentpos+2);
  //We are assigining the value after recursion to the current node.
  segtree[currentpos] = min(segtree[2*currentpos+1],segtree[2*currentpos+2]);
}

// Curr here is the current position. Left and right are the boundaries of the query, and low and
// high are the boundaries of the segment tree
int rangeminquery(int *segtree, int left, int right, int low, int high, int curr)
{

  // CASE 1: The given segment tree node range lies completely inside the query range
  // Return that node.
  if (left <= low && right >= high) return segtree[curr];
  
  // CASE 2: The given seg tree node is completely disjoint; return some arbitrary max
  else if (left > high || right < low) return MAX;
  // CASE 3: Partially in node range.
  // divide the range of seg tree node in 2. Call the function on the child (which has that range)
  // do this for each half of division.
  int mid = (low+high)/2;
  return min(rangeminquery(segtree, left, right, low, mid, 2*curr+1), rangeminquery(segtree, left, right, mid+1, high, 2*curr+2));
}


// update one node and reflect effects on all nodes having that node in their range.

void updatesegtree(int *segtree, int index, int difference, int left, int right, int curr)
{

  // If seg tree node is disjoint from updaed node
  if (index < left || index > right) return;
  
  if (left == right)
  {
    segtree[curr] += difference;
    return;
  }
  int mid = (left+right)/2;
  updatesegtree(segtree, index, difference, left, mid, 2*curr+1);
  updatesegtree(segtree, index, difference, mid+1, right, 2*curr+2);
  segtree[curr] = min(segtree[2*curr+1],segtree[2*curr+2]);
}
// You can also start from the child and keep checking/updating the parent.

void main()
{
  int numele;
  printf ("Enter the number of elements you want in your array: ");
  scanf("%d", &numele);
  int *array = (int *)malloc(numele*sizeof(int));
  for (int i = 0; i < numele; i++) scanf("%d", (array+i));
  int *segtree = (int *)malloc((2*numele-1)*sizeof(int));
  buildsegtree(array, segtree, 0, numele-1, 0);
  /*2 8 -11 3 -87 1*/
  updatesegtree(segtree, 4, 77, 0, numele-1, 0);
  printf ("%d\n", rangeminquery(segtree, 0, 3, 0, numele-1, 0));
  for (int i = 0; i < 2*numele-1; i++) printf ("%d ", segtree[i]);
  //printf ("\n");
}
