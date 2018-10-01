#include <iostream>
using namespace std;
  
// Function to swap, using call by reference
void swap(int& a, int& b) 
{ 
    int temp = a; 
    a = b; 
    b = temp; 
} 
  
// Actual Bubble sort 
void bubbleSort(int arr[], int size) 
{ 
   int i, j; 
   for (i = 0; i < size-1; i++)       
  {
       for (j = 0; j < (size-1)-i; j++)             
           if (arr[j] > arr[j+1])                 
              swap(arr[j], arr[j+1]); 
  }
} 
  
/* Function to print an array */
void print(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout<<arr[i]<<' ';
    cout<<endl;
} 

int main() 
{ 
    int arr[] = { 7, 89, 44, 11, 4, 12, 9 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    bubbleSort(arr, n); 
    printArray(arr, n); 
    return 0; 
} 
