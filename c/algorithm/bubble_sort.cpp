#include <iostream>

using namespace std;


// Function for performing sort in ascending order using Bubble Sort Algorithim

void BSort(int arr[], int N){
    int i,j,temp;
    for(i = 0 ;i<N-1 ;i++) {
        for(j = 0; j<=i ; j++) {
            if(arr[j] < arr[j+1])
                temp = arr[j] ;
                arr[j] = arr[j+1] ;
                arr[j+1] = temp;
        }
    }
}
