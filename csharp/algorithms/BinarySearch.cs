using System;

namespace BinarySearchApplication
{
    class BinarySearch
    {
        static void Main(string[] args)
        {
            int[] arr = {10, 30, 40, 50, 60};
            Console.WriteLine("Enter the element to be searched");
            int X = int.Parse(Console.ReadLine().Trim());
            int result = SearchElementX(arr,X,0,arr.Length);
            if(result == -1)
                Console.WriteLine("Element Not Found");
            else
            {
                Console.WriteLine("Element Found At Index: "+result);
            }
            Console.ReadLine();
        }

        static int SearchElementX(int[] arr, int X, int left,int right)
        {
            while (left <= right)
            {
                int mid = left + (right - left)/2;

                if (arr[mid] == X)
                    return mid;

                if (arr[mid] < X)
                    return SearchElementX(arr, X, mid + 1, right);

                if (arr[mid] > X)
                    return SearchElementX(arr, X, left, mid-1);
            }
            return -1;
        }
    }
}
