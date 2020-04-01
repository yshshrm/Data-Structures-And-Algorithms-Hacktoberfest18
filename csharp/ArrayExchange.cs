//this code is designed to show how a simple exchange of array data will function

      public static void exchange (int[] data, int m, int n) //params are the array itself, 1st data position, and 2nd data position. 
      {
         int temporary; //temporary spot to hold data whilst swapping

         temporary = data [m]; //temp variable reads location m
         data [m] = data [n];  //location m copies location n data
         data [n] = temporary; //location n copies data originally from location m
      }
