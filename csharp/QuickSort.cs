using System;

namespace QuickSort {
	class Program {
		static void swap(ref int a, ref int b) {
			int c = a;
				a = b;
				b = c;
		}

		static void sort(int[] arr) {
			int length = arr.Length;
			for (int i = 0; i < length - 1; i++) {
				for (int j = i + 1; j < length; j++) {
					if (arr[i] > arr[j]) {
						swap(ref arr[i], ref arr[j]);
					}
				}
				
			}
		}

		static void Main() {
			int[] arr = { 9, 4, 5, 6, 5, 3, 2, 10, 200, 1 };
			sort(arr);
			for (int i = 0; i < arr.Length; i++) {
				Console.Write($"{arr[i]} ");
			}
			Console.WriteLine();
		}
	}
}