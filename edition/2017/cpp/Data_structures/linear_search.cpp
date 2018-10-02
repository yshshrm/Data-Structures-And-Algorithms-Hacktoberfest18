/**
*linear search
*
*
**/


#include <iostream>
#include <stdlib.h>

using namespace std;

int linear_search(int arr[], int ele);
int main()
{
    int arr[] = {2, 3, 4 ,6 ,7};
    int ans = linear_search(arr, 7);
    if(ans == 0)
        cout<<"found!\n";
    else
        cout<<"not found!\n";
    return 0;
}
int linear_search(int arr[], int ele)
{
    int i;
    int len = sizeof(arr);
    for(i = 0; i < len; i++)
    {
        if(arr[i] == ele)
            return 0;
    }
    return 1;
}
