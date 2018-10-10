using System;

class MergeSortAlgorithm
{
    public static void MergeSort(int[] input, int low, int high)
    {
        if (low < high)
        {
            int middle = (low / 2) + (high / 2);
            MergeSort(input, low, middle);
            MergeSort(input, middle + 1, high);
            Merge(input, low, middle, high);
        }
    }

    public static void MergeSort(int[] input)
    {
        MergeSort(input, 0, input.Length - 1);
    }

    private static void Merge(int[] input, int low, int middle, int high)
    {

        int left = low;
        int right = middle + 1;
        int[] tmp = new int[(high - low) + 1];
        int tmpIndex = 0;

        while ((left <= middle) && (right <= high))
        {
            if (input[left] < input[right])
            {
                tmp[tmpIndex] = input[left];
                left = left + 1;
            }
            else
            {
                tmp[tmpIndex] = input[right];
                right = right + 1;
            }
            tmpIndex = tmpIndex + 1;
        }

        if (left <= middle)
        {
            while (left <= middle)
            {
                tmp[tmpIndex] = input[left];
                left = left + 1;
                tmpIndex = tmpIndex + 1;
            }
        }

        if (right <= high)
        {
            while (right <= high)
            {
                tmp[tmpIndex] = input[right];
                right = right + 1;
                tmpIndex = tmpIndex + 1;
            }
        }

        for (int i = 0; i < tmp.Length; i++)
        {
            input[low + i] = tmp[i];
        }

    }

    public static string PrintArray(int[] input)
    {
        string result = String.Empty;

        for (int i = 0; i < input.Length; i++)
        {
            result = result + input[i] + " ";
        }
        if (input.Length == 0)
        {
            result = "Array is empty.";
            return result;
        }
        else
        {
            return result;
        }
    }
}
