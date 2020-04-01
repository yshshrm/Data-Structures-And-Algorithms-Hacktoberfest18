using System;
using System.ComponentModel;

namespace BogoSort
{
    public class BogoSorter
    {
        public enum SortMode
        {
            Ascending,
            Descending
        }
        
        private Random rng;
         public BogoSorter()
        {
            rng = new Random();
        }
        
        // https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
        public void Shuffle(ref int[] numbers)
        {
            for (int i = numbers.Length - 1; i > 1; i--)
            {
                int randIndex = rng.Next(i + 1);
                int temp = numbers[randIndex];
                numbers[randIndex] = numbers[i];
                numbers[i] = temp;
            }
        }
         public bool IsSorted(in int[] numbers, SortMode sortMode)
        {
            switch (sortMode)
            {
                case SortMode.Ascending:
                    return IsSortedAscending(numbers);
                    break;
                
                case SortMode.Descending:
                    return IsSortedDescending(numbers);
                    break;
                
                default:
                    throw new InvalidEnumArgumentException();
            }
        }
         private bool IsSortedAscending(in int[] numbers)
        {
            for (int i = 0; i < numbers.Length; i++)
            {
                if (i + 1 >= numbers.Length)
                {
                    // We made it to the end of the array, without finding any out of place numbers.
                    return true;
                }
                
                // If we find a number out of place, we failed.
                if (numbers[i] > numbers[i + 1])
                {
                    return false;
                }
            }
             return true;
        }
         private bool IsSortedDescending(in int[] numbers)
        {
            for (int i = 0; i < numbers.Length; i++)
            {
                if (i + 1 >= numbers.Length)
                {
                    // We made it to the end of the array, without finding any out of place numbers.
                    return true;
                }
                
                // If we find a number out of place, we failed.
                if (numbers[i] < numbers[i + 1])
                {
                    return false;
                }
            }
             return true;
        }
    }
}