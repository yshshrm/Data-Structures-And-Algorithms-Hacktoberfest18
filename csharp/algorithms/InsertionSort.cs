using System;

class InsertionSortAlgorithm
{
    public static void InsertionSort(int[] array)
    {
        for (int i = 1; i < array.Length; i++) {
            int key = array[i];
            int j = i - 1;
            while (j >= 0 && array[j] > key) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                j -= 1;
            }
            array[j + 1] = key;
        }
    }

    public static void Main()
    {
        int[] array = { 0, 8, 4, 7, 1, 9, 10, 5, 2, 11, 3 };

        for(int i = 0; i < array.Length; i++)
        {
            Console.Write(array[i] + " ");
        }

        Console.WriteLine();
        InsertionSort(array);

        for(int i = 0; i < array.Length; i++)
        {
            Console.Write(array[i] + " ");
        }
    }
}