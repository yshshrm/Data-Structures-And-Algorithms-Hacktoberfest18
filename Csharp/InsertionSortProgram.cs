using System;

namespace InsertionSort
{
    class InsertionSortProgram
    {
        static void Main(string[] args)
        {
            int[] arr = {10, 30, 20, 40, 5};
            SortArray(arr);
            
        }

        private static void SortArray(int[] arr)
        {
            int n = arr.Length;

            for (int i = 1; i < n; i++)
            {
                int element = arr[i];
                int j = i - 1;

                while (j >= 0 && arr[j] > element)
                {
                    arr[j + 1] = arr[j];
                    j = j - 1;
                }
                arr[j + 1] = element;
            }

            foreach (int item in arr)
                Console.Write(item + " ");
            Console.Read();

        }

    }
}
