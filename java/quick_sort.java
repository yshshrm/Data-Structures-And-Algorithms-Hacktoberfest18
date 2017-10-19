public class QuickSort
{
   public static void swap (int A[], int x, int y)
   {
      int temp = A[x];
      A[x] = A[y];
      A[y] = temp;
   }

   public static int partition(int A[], int f, int l)
   {
      int pivot = A[f];
      while (f < l)
      {
         while (A[f] < pivot) f++;
         while (A[l] > pivot) l--;
         swap (A, f, l);
      }
      return f;
   }

   public static void Quicksort(int A[], int f, int l)
   {
      if (f >= l) return;
      int pivot_index = partition(A, f, l);
      Quicksort(A, f, pivot_index);
      Quicksort(A, pivot_index+1, l);
   }
}