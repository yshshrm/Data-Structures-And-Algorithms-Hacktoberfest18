using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Armstrong
{
    class Program
    {
        static void Main(string[] args)
        {
            int num, remainder, sum = 0;
            Console.Write("Enter a number : ");
            num = int.Parse(Console.ReadLine());
            for (int i = num; i > 0; i = i / 10)
            {
                remainder = i % 10;
                sum = sum + remainder * remainder * remainder;
            }
            if (sum == num)
            {
                Console.Write("Entered number is an Armstrong number.");
            }
            else
                Console.Write("Entered number is not an Armstrong number.");
            Console.ReadLine();
        }
    }
}
