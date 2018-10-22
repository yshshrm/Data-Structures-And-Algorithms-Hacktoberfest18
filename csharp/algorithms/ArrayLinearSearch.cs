//this algorithm searches for the position of a given item in an array.

      public static int ArrayLinearSearch(int[] data, int item) { //params are the array, and the int you wish to search for
         int N=data.Length; //length for search
         for (int i=0; i < N; i++) 
            if (data[i] == item) //check to see if item matches an array item
               return i; //returns array position
         return -1;
      }
