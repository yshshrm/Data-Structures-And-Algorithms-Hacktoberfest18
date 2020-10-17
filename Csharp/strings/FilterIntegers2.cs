using System;
using System.Collections.Generic;

namespace ConsoleApp
{
    //This would probably make a better extension method than standalone function.

    class Program
    {
        static void Main(string[] args)
        {
            string cookie = "c00kie : ";
            string all = "1a2b3c4d5e6f7g8h9i0j : ";

            Console.WriteLine(cookie);
            PrintEnumerable(FindIntsInString(cookie));
            Console.WriteLine();

            Console.WriteLine(all);
            PrintEnumerable(FindIntsInString(all));
            Console.WriteLine();

            Console.WriteLine("Press the [any] key to continue...");
            Console.ReadKey(true);
        }

        private static void PrintEnumerable<T>(IEnumerable<T> input)
        {
            foreach (var item in input)
            {
                Console.Write(item);
            }
            Console.WriteLine();
        }

        private static IEnumerable<int> FindIntsInString(string input)
        {
            for (int i = 0; i < input.Length; i++)
            {
                var curChar = input[i];
                if(char.IsNumber(curChar))
                {
                    yield return curChar - 48;
                }
            }
        }
    }
}
