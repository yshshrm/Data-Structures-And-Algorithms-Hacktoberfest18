#include <stdio.h>
#define SIZE 100
int linearSearch(int a[], int query, int size);

int main()
{
   int data[ SIZE ], i, temp;
   int searchQuery; 

   for (i = 0; i < SIZE; ++i)
   {
      data[ i ] = 2 * i;
   }

   printf("Enter integer to search for: ");
   scanf("%d", &searchQuery);

   temp = linearSearch(data, searchQuery, SIZE);

   if ( temp != -1)
      printf("Found value in element %d.", temp);
   else
      printf("Value not found.");

   return 0;
}


int linearSearch(int a[], int query, int size)
{
   int j; 
   for (j = 0; j < size; ++j)
   {
      if ( a[ j ] == query)
      {
         return j; //return location of value
      }
   }

   return -1; //value not found
}
