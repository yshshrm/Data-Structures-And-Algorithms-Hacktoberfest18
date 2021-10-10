// Name: JHALA DEVRAJSINH SHRIPALSINH
// Date: 01/07/2021
// Purpose: Count Sort time complexity better than Quick Sort and Merge Sort
// Approach:
// 1. Find the count of every distinct element in the array
// 2. Calculate the position of each element in the sorted array

// Time Complexity:
// max(Ai,N) Ai = Creating array of appropriate range && Iterate the frequency array
// N = Filling frequencies of each element

#include<bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n)
{

    int k = arr[0];
    for(int i=0;i<n;i++)
    {
        k = max(k,arr[i]);
    }

    int count[10] = {0};
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }

    for(int i=1; i<=k;i++)
    {
        count[i] += count[i-1];
    }

    int output[n];
    for(int i=n-1; i>=0;i++)
    {
        output[--count[arr[i]]] = arr[i];
    }

    for(int i=0;i<n;i++)
    {
        arr[i] = output[i];
    }

}


int main()
{

    int arr[] = {1,3,2,3,4,1,6,4,3};
    countSort(arr,9);
    for(int i=0;i<9;i++)
    {
        cout << arr[i] << " ";
    }

    return 0;

}