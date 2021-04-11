using System;

namespace LargestNumber {
	class Program {
		static int GetLargest(int[] arr) {
			int length = arr.Length;
			if (length == 0) {
				return 0;
			} else {
				int largest = arr[0];
				foreach (int item in arr) {
					if (item > largest) {
						largest = item;
					}
				}
				return largest;
			}
		}
		static void Main() {
			int[] arr = { 9, 4, 5, 6, 5, 3, 2, 10, 200, 1 };
			Console.WriteLine(GetLargest(arr));
		}
	}
}