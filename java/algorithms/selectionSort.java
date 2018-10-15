package com.myjavasort.algos;
 
public class MySelectionSort {
 
    public static int[] doSelectionSort(int[] arr){
         
        for (int i = 0; i < arr.length - 1; i++)
        {
            int index = i;
            for (int j = i + 1; j < arr.length; j++)
                if (arr[j] < arr[index]) 
                    index = j;
      
            int lowerNumber = arr[index];  
            arr[index] = arr[i];
            arr[i] = lowerNumber;
        }
        return arr;
    }
     
    public static void main(String a[]){
         
        int[] arr1 = {24,34,2,84,8,64,88,44};
        int[] arr2 = doSelectionSort(arr1);
        for(int i:arr2){
            System.out.print(i);
            System.out.print(", ");
        }
    }
}
