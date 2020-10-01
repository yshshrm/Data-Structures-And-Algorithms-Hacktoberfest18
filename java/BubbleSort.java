class BubbleSort
{
    void bubbleSort(int array[])
    {
        int l = array.length;
        for (int i = 0; i < l-1; i++)
        {
            for (int j = 0; j < l-i-1; j++)
            {
                if (array[j] > array[j+1])
                {
                    int dup = array[j];
                    array[j] = array[j+1];
                    array[j+1] = dup;
                    }
                  }
               }
            }
        }
 
