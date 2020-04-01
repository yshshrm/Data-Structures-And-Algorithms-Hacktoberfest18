using System;

namespace BinarySearch
{
    class Program
    {

        public static int BinSearch(int[] x, int searchValue)
        {
            // Returns index of searchValue in sorted array x, or -1 if not found
            int left = 0;
            int right = x.Length;
            return binarySearch(x, searchValue, left, right);
        }

        public static int binarySearch(int[] x, int searchValue, int left, int right)
        {
            if (right < left)
            {
                return -1;
            }
            int mid = (left + right) >> 1;
            if (searchValue > x[mid])
            {
                return binarySearch(x, searchValue, mid + 1, right);
            }
            else if (searchValue < x[mid])
            {
                return binarySearch(x, searchValue, left, mid - 1);
            }
            else
            {
                return mid;
            }
        }

        static void Main()
        {
            //first you need to sort your array
            int[] A = { 1, 2, 4, 6, 7, 9, 11, 42, 300, 302 }; // Random test data
            int result = BinSearch(A, 9);
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
