using System;

namespace MergeSort
{
    class Program
    {

        static int LinearSearch(int[] x, int valueToFind)
        {
            for (int i = 0; i < x.Length; i++)
            {
                if (valueToFind == x[i])
                {
                    return i;
                }
            }
            return -1;

        }

        static void Main()
        {
            int[] A = { 9, 4, 5, 6, 5, 3, 2, 10, 200, 1 }; // Random test data
            int result = LinearSearch(A, 22);
            if (result==-1)
            {
                Console.WriteLine("Value not exists");
            }
            else
            {
                string resultString = "Value on index " + result;
                Console.WriteLine(resultString);
            }

        }
    }
}
