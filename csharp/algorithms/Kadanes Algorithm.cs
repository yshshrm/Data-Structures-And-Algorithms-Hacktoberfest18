using System;

class MyProgram {
  // function for kadane's algorithm
  static void kadane(int[] Array) {
    int max_sum = 0;
    int current_sum = 0;
    
    int max_start = 0;
    int max_end = 0;
    int current_start = 0;
    int current_end = 0;

    int n = Array.Length;
    for(int i=0; i<n; i++) 
    {
      current_sum = current_sum + Array[i];
      current_end = i;
      if (current_sum < 0)
      {
        current_sum = 0;
        //Start a new sequence from next element
        current_start = current_end + 1;
      }
      if(max_sum < current_sum)
      {
        max_sum = current_sum;
        max_start = current_start;
        max_end = current_end;
      }
    }
    Console.WriteLine("Maximum SubArray is: " + max_sum);
    Console.WriteLine("Start index of max_Sum: " + max_start);
    Console.WriteLine("End index of max_Sum: " + max_end);
  }

  // test the code
  static void Main(string[] args) {
      int n = int.Parse(Console.ReadLine());
      Console.WriteLine("/nEnter elements of Array");
      int[] arr = new int[n]; 
      for(int i=0; i<n; i++) 
      { arr[i] = int.Parse(Console.ReadLine()); }
    
       kadane(arr);
  }
}
