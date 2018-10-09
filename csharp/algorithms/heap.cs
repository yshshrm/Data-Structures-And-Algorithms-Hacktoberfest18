 class Program
    {
        static void Main(string[] args)
        {
            int[] arr = { 10, 64, 7, 52, 32, 18, 2, 48};
            HeapSort hs = new HeapSort();
            hs.PerformHeapSort(arr);
            Console.ReadLine();
        }
    }
    class HeapSort
    {
        private int heapSize;

        private void BuildHeap(int[] arr)
        {
            heapSize = arr.Length-1;
            for (int i = heapSize/2; i >= 0; i--)
            {
                Heapify(arr, i);
            }
        }

        private void Swap(int[] arr, int x, int y)//function to swap elements
        {
            int temp = arr[x];
            arr[x] = arr[y];
            arr[y] = temp;
        }
        private void Heapify(int[] arr, int index)
        {
            int left = 2 * index;
            int right = 2 * index + 1;
            int largest = index;

            if (left <= heapSize && arr[left] > arr[index])
            {
                largest = left;
            }

            if (right <= heapSize && arr[right] > arr[largest])
            {
                largest = right;
            }

            if (largest != index)
            {
                Swap(arr, index, largest);
                Heapify(arr, largest);
            }
        }
        public void PerformHeapSort(int[] arr)
        {
            BuildHeap(arr);
            for (int i = arr.Length-1; i >= 0; i--)
            {
                Swap(arr, 0, i);
                heapSize--;
                Heapify(arr, 0);
            }
            DisplayArray(arr);
        }
        private void DisplayArray(int[] arr)
        {
            for (int i = 0; i < arr.Length; i++)
            { Console.Write("[{0}]", arr[i]); }
        }
    }

