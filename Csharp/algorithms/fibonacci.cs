using System;
					
public class Program
{
	public static void Main()
	{
		Fibonacci_Recursive(10);
	}
	
	
	private static void Fibonacci_Recursive(int len)
        {
           Fibonacci_Rec_Temp(0, 1, 1, len);
       }
 
	private static void Fibonacci_Rec_Temp(int a, int b, int counter, int len)
        {
            if (counter <= len)
            {
                Console.Write("{0} ", a);
               Fibonacci_Rec_Temp(b, a + b, counter+1, len);
            }
       }
}
