#include <stdio.h>  
using namespace std;
#define MAX 100
void shell_sort(int arr[], int num)    
{    
      int i, j, k, tmp;    
          for (i = num / 2; i > 0; i = i / 2)    
            {    
               for (j = i; j < num; j++)    
                  {    
                     for(k = j - i; k >= 0; k = k - i)    
                        {    
                          if (arr[k+i] >= arr[k])    
                                 break;    
                          else    
                            {    
                               tmp = arr[k];    
                               arr[k] = arr[k+i];    
                               arr[k+i] = tmp;    
                             }    
                          }    
                    }    
                }    
}    

int main()    
{    
int arr[MAX];    
int k,  num;    
printf("Enter total no. of elements : ");    
scanf("%d", &num);    
printf("\nEnter %d numbers: ", num);    
  
          for (k =  0 ; k < num; k++)    
                  scanf("%d", &arr[k]);    
    
shellsort(arr, num);    
printf("\n Sorted array is: ");    
             for (k = 0; k < num; k++)    
                       printf("%d ", arr[k]);    
return 0;    
}    
