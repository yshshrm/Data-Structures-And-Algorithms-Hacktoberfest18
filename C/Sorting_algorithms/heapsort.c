
//
//  Created by djsdvg on 26/10/17.
//
#define ARRAY_SIZE 100
#include <stdio.h>
#include <stdlib.h>

void heapify (int array[],int length, int i);
void build_heap(int array[],int length);
void heap_sort(int array[],int length);

int main(int argc, const char * argv[]) {
    
    int array[ARRAY_SIZE];
    int i;
    for(i=1;i<ARRAY_SIZE;i++)
        array[i]=rand()%ARRAY_SIZE;
    
    heap_sort(array, ARRAY_SIZE-1);
    
    for(i=1;i<ARRAY_SIZE;i++)
        printf("%d\n",array[i]);
    
    return 0;
}


void heapify (int array[],int length, int i){
    int l=i*2;
    int r=l+1;
    int largest;
    
    if (l<=length && array[l]>array[i])
        largest=l;
    else
        largest=i;
    
    if(r<=length && array[r]>array[largest])
        largest=r;
    if (largest!=i){
        int temp=array[i];
        array[i]=array[largest];
        array[largest]=temp;
        heapify(array, length, largest);
    }
}

void build_heap(int array[],int length){
    int i;
    for(i=length/2;i>0;i=i-1)
        heapify(array, length,i);
}

void heap_sort(int array[],int length){
    build_heap(array, length);
    int i;
    for(i=length;i>1;i=i-1){
        int temp=array[i];
        array[i]=array[1];
        array[1]=temp;
        length--;
        heapify(array, length,1);
    }
}

