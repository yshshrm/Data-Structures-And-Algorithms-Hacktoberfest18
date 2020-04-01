#include<iostream>
#include<algorithm>
using namespace std;

void quickSort(int input[], int size) {
 if(size<=1)
   return;
  
  int pivot=0,count=0;
  
  for(int i=1;i<size;i++)
    if(input[i]<=input[pivot])
      count++;
  
  swap<int>(input[pivot],input[count]);
  pivot=count;
  
  int l=0,r=size-1;
  
  while(l<r)
  {
    while(input[l]<=input[pivot] && l<pivot)
      l++;
    if(l>=pivot)
      break;
      while(input[r]>input[pivot] )
      r--;
    
    swap<int>(input[l++],input[r--]);
      }
   quickSort(input,pivot);
   quickSort(input+pivot+1,size-pivot-1);
 
}
