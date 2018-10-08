static void BubbleSort(int[] arr){
	for (int i = 0; i < arr.Length - 1; i++)	{
		for (int j = 0; j < arr.Length - i - 1; j++){
			if (arr[j + 1] < arr[j]){
				int tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
