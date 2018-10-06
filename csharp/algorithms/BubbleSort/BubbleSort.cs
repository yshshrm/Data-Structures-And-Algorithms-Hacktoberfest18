static void BubbleSort(int[] array)
{
	for(int i = 0; i < array.Length; i++)
	{
		for(int j = 0; j < array.Length - 1; j++)
		{
			if(array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

static void Tryit()
{
	int[] array = { 2, 6, 9, 1, 10 };

	for(int i = 0; i < array.Length; i++)
	{
		Console.Write(array[i] + " ");
	}

	Console.WriteLine();
	BubbleSort(array);

	for(int i = 0; i < array.Length; i++)
	{
		Console.Write(array[i] + " ");
	}
}