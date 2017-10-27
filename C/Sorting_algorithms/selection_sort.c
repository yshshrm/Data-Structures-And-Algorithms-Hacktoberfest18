//
//  Created by djsdvg on 25/10/17.
//
#include<stdlib.h>
#include <stdio.h>
#define SIZEARRAY 1000 //size of array
int main (void){
    
    int array[SIZEARRAY];//declaration of array
    int j,i,posmin;
    for(j=0;j<SIZEARRAY;j++)//initialization of the array with random numbers
        array[j]=rand();
    
    for(i=0;i<SIZEARRAY;i++){
        posmin=i;    //suppose that the first number is the smallest
        for(j=i+1;j<SIZEARRAY;j++)
            if(array[j]<array[posmin]) //if i find a smaller number
                posmin=j;               //i update the position
        int temp=array[i];         //at the end of the cycle swap the position...
        array[i]=array[posmin];   //...of the first number of my subarray and...
        array[posmin]=temp;       //...the smallest number of my subarray
    }
    
    
    for(i=0;i<SIZEARRAY-1;i++) //print ordered array
         printf("%d\n",array[i]);
    
    
    
    return 0;
}
