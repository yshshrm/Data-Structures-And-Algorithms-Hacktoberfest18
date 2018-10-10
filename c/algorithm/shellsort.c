#include <stdio.h>
void print_arr(int arr[],int size);
void shellSort(int arr[],int size);
void print_arr(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void shellSort(int arr[],int size){
    for (int m=size/2; m>0;m/= 2) 
    {  
        for (int i=m;i<size;i+=1) 
        {
            int temp = arr[i]; 
            int j;             
            for (j = i; j >=m && arr[j-m] > temp; j-=m){
                arr[j] = arr[j-m]; 
            }
            arr[j] = temp; 
        } 
    }
}
int main(){
    int arr[100];
    printf("Enter a number (size of array<100): ");
    int arr_size;scanf("%d",&arr_size);
    for(int i=0;i<arr_size;i++){scanf("%d",&arr[i]);}
    printf("Array before Sorting: ---  ");
    print_arr(arr,arr_size);
    printf("Array After Sorting: ---  ");
    shellSort(arr,arr_size);
    print_arr(arr,arr_size);
    return 0;
}