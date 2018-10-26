using System;
using System.Diagnostics;
using System.Linq;
using System.Numerics;
 namespace BogoSort
{
    class Program
    {
        static void Main(string[] args)
        {
            BigInteger attempts = 0;
            var numbers = MakeRandomNumbers(10);
            var sorter = new BogoSorter();
            var stopwatch = new Stopwatch();
            stopwatch.Start();
            while (!sorter.IsSorted(numbers, BogoSorter.SortMode.Ascending))
            {
                sorter.Shuffle(ref numbers);
                attempts++;
            }
            stopwatch.Stop();
            
            Console.WriteLine($"Array sorted after {attempts:N} attempts.");
            Console.WriteLine($"Sorting done in: {stopwatch.Elapsed}");
            Console.WriteLine(string.Join(',', numbers));
        }
         public static int[] MakeRandomNumbers(int numbersToGenerate)
        {
            var rng = new Random();
            return Enumerable
                .Repeat(0, numbersToGenerate)
                .Select(i => rng.Next())
                .ToArray();
        }
    }
}