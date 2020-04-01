/*
  Contribuor - Manilal Kasera
  InsertionSort in c;

*/

#include <stdio.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void insertionSort(int a[], int n){

    for(int i=0;i<n;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[minIndex])
                minIndex = j;
        }

        swap(&a[i], &a[minIndex]);
    }
}

int main(){
 
    int a[] = {7,5,2,3, 2};
    int n =5;
    insertionSort(a,5);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    
    return 0;
}
