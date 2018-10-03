public class SequentialSearch{

//Returns -1 if index is not found in the array
   public static int sequentialSearch(int[] elements, int target){
      for (int j = 0; j < elements.length; j++)
      {
         if (elements[j] == target)
         {
            return j;
         }
     }
     return -1;
   }

   public static void main(String[] args){
	   int[] elements = new int[]{0,9,13,14,5,6,10038,24,25,3,4};
	   System.out.println(sequentialSearch(elements, 5));
	   System.out.println(sequentialSearch(elements, 139));
	   System.out.println(sequentialSearch(elements,25));
   }
}
    
