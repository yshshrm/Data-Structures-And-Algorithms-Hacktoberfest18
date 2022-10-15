using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FibonacciCSharp
{
    class Program
    {
        static int fibonacci(int n)
        {
            int[] f = new int[n + 1];
            int i;

            f[0] = 0;
            f[1] = 1;

            for(i = 2; i <= n; i++)
            {
                f[i] = f[i - 1] + f[i - 2];
            }

            return f[n];
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Write the nth term for which you'd like to find the fibonacci number for: ");
            int number = Convert.ToInt32(Console.ReadLine());

            int sum = fibonacci(number);

            Console.WriteLine(sum);
            Console.ReadKey();
        }
    }
}
