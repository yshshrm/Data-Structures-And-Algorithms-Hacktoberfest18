public class binary_search {  
 public static int binarySearch(int arr[], int val){
    int l = 0, r = arr.length - 1;
    while(l <= r){  
      int mid = (l + r) >> 1;  
      if (arr[mid] == val){  
        return mid;  
      } else if(arr[mid] < val){  
        l = mid + 1;     
      }else{  
         r = mid - 1;  
      }
   }
   return -1;
 }
 public static void main(String args[]){  
    int arr[] = {10,20,30,40,50};  
    int val = 30;  
    int ans = binarySearch(arr,val);
    System.out.println((ans == -1) ? "Element not found" : "Element is found at index: " + ans);  
 }
}

