#include<iostream>
using namespace std;
int InterpolationSearch(int A[],int size,int data){
    int low=0,mid,high=size-1;
    while(low<=high){
        mid=low+(((data-A[low])*(high-low))/(A[high]-A[low]));
        if(data==A[mid])
            return mid+1;
        if(data<A[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}
