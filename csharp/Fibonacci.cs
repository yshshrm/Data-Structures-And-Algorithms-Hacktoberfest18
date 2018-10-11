using System;

namespace Fibonacci
{
    internal class Fibonacci
    {
        private static long Fib(int fib)
        {
            if (fib <= 2)
                return 1;
            long prev = 1, cur = 1;
            for (var i = 2; i < fib; ++i)
            {
                var tmp = cur;
                cur += prev;
                prev = tmp;
            }

            return cur;
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Fibonacci: ");
            var line = Console.ReadLine();
            if (line != null)
            {
                var value = Fib(int.Parse(line));
                Console.Out.WriteLine(value);
            }
        }
    }
}
