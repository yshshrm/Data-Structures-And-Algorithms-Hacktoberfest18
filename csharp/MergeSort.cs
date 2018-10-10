using System;

namespace MergeSort {
    class Program {
        static void merge(int[] A, int p, int q, int r)
        {
        	int s1 = q-p+1, s2=r-q;
        	int[] L= new int[s1];
            int[] R= new int[s2];
        	int i,j;
        	for (i=0; i<s1; i++) L[i] = A[p+i];
        	for (i=0; i<s2; i++) R[i] = A[q+i+1];
        	i=j=0;
        	for (int k=p; k<=r; k++)
        	{
        		if (j==s2 || (i!=s1 && L[i]<=R[j]))
        		{
        			A[k] = L[i];
        			i++;
        		}
        		else if (i==s1 || j!=s2)
        		{
        			A[k] = R[j];
        			j++;
        		}
        	}

        }

        static void mergeSort(int[] A, int start, int end) {
            if (start < end) {
                int q=(start+end)/2;
                mergeSort(A, start, q);
                mergeSort(A, q+1, end);
                merge(A, start, q, end);
            }
        }

   

        static void Main()
        {
            int[] A = {9,4,5,6,5,3,2,10,200,1}; // Random test data
            Console.Write("UNSORTED:\n");
            for(int i=0; i<A.Length; i++) Console.Write(A[i]+" ");
            Console.Write("\n");    
            mergeSort(A, 0, A.Length-1);
            Console.Write("SORTED:\n");
            for(int i=0; i<A.Length; i++) Console.Write(A[i]+" ");
            Console.Write("\n");     
        }
    }
}
