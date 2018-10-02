import java.util.*;
 
//Bucket Sort Method
public class Bucket{
 
   public static void sort(int[] arr, int maximum) {
      int [] bucket=new int[maximum+1];
      
      for (int i=0; i<bucket.length; i++) {
         bucket[i]=0;
      }
      //loop through length of array
      for (int i=0; i<arr.length; i++) {
         bucket[arr[i]]++;
      }
 
      int pos=0;
      for (int i=0; i<bucket.length; i++) {
         for (int j=0; j<bucket[i]; j++) {
            arr[pos++]=i;
         }
      }
   }
 
 
   public static void main(String[] args) {
      int maximum=5;
      int [] numbers= {5,0,4,3,2,1,0,3,2,5,1,4}; 
      
      //Print before and after of toStrings
      System.out.println("Before: " + Arrays.toString(data));
      sort(numbers,maximum);
      System.out.println("After:  " + Arrays.toString(data));
   }
}
