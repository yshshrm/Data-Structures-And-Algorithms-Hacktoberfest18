#include <stdio.h>

int *bubblesort(int *numbers, int arraysize)
{
    for (int i = 0; i < arraysize; i++)
    {
        for (int j = arraysize - 1; j > 0; j--)
        {
            if (numbers[j] < numbers[j-1])
            {
                numbers[j] = numbers[j] + numbers[j-1];
                numbers[j-1] = numbers[j] - numbers[j-1];
                numbers[j] = numbers [j] - numbers[j-1];
            }
        }
    }
    return numbers;
}
