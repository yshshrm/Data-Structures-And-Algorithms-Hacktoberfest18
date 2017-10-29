using System;

namespace Algorithms
{
    public class MergeSort
    {
        public int[] Sort(int[] array)
        {
            if (array.Length <= 1)
            {
                return array;
            }

            var middle = array.Length / 2;

            var left = new int[middle];
            var right = new int[array.Length - middle];

            Array.Copy(array, left, middle);
            Array.Copy(array, middle, right, 0, right.Length);

            left = Sort(left);
            right = Sort(right);

            return Merge(left, right);
        }

        public int[] Merge(int[] left, int[] right)
        {
            var merged = new int[left.Length + right.Length];

            var i = 0;
            var j = 0;

            for (var k = 0; k < merged.Length; k++)
            {
                if (left[i] < right[j])
                {
                    merged[k] = left[i++];
                }
                else
                {
                    if (right[j] < left[i])
                    {
                        merged[k] = right[j++];
                    }
                }

                if (j >= right.Length)
                {
                    return copy(left, i, merged, ++k);
                }

                if (i >= left.Length)
                {
                    return copy(right, j, merged, ++k);
                }
            }

            return merged;
        }

        private int[] copy(int[] source, int sourceIndex, int[] destination, int destinationIndex)
        {
            var index = destinationIndex;

            for (var i = sourceIndex; i < source.Length; i++)
            {
                destination[index++] = source[i];
            }

            return destination;
        }
    }
}
