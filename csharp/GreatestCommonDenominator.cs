using System;

namespace Fibonacci
{
    internal class GreatestCommonDenominator
    {
        private static long gcd(int left, int right)
        {
            int remainder;
            do
            {
                remainder = left % right;
                left = right;
                right = remainder;
            } while (remainder != 0);
            return left;
        }

        static void Main(string[] args)
        {
            Console.WriteLine("GCD:");
            Console.Write("L: ");
            var left = Console.ReadLine();
            Console.Write("R: ");
            var right = Console.ReadLine();
            if (left != null && right != null)
            {
                var value = gcd(int.Parse(left), int.Parse(right));
                Console.Out.WriteLine(value);
            }

            Console.ReadKey();
        }
    }
}
