using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;


namespace InsertionSort
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] values = new int[10] {3, 6, -2, 0,15, 24, 21,38, 41, 1};
            Console.WriteLine("Array elements before sort");
			PrintArray(values);
            Console.WriteLine("\nArray elements after sort");
            PrintArray(InsertionSort(values));
        }

        static int[] InsertionSort(int[] a)
        {
            for (int i = 0; i < a.Length - 1; i++)
            {
                for (int j = i + 1; j > 0; j--)
                {
                    if (a[j - 1] > a[j])
                    {
                        int temp = a[j - 1];
                        a[j - 1] = a[j];
                        a[j] = temp;
                    }
                  }
            }
            return a;         
        }
        public static void PrintArray(int[] array)
        {
            foreach (int i in array)
            {
                Console.Write(i.ToString() + "  ");
            }
         }

       
        public static int[] InsertionSortByShift(int[] a)
        {
            for (int i = 0; i < a.Length - 1; i++)
            {
                int j;
                var insertionValue = a[i];
                for (j = i; j > 0; j--)
                {
                    if (a[j - 1] > insertionValue)
                    {
                        a[j] = a[j - 1];
                    }
                }
                a[j] = insertionValue;
            }
            return a;
        }

     }
}
