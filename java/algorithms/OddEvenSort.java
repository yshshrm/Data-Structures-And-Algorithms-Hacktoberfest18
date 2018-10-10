class OddEven
{
	private long[] a;
	private int nElems;
	public OddEven(int max)
	{
		a = new long[max];
		nElems = 0;
	}
	public void insert(long value)
	{
		a[nElems] = value;
		nElems++;
	}
	public void display()
	{
		for(int j=0; j<nElems; j++)
		System.out.print(a[j] + " ");
		System.out.println();
	}
	public void oddEvenSort()
	{
		int i,j,k=0;
		while(k<nElems/2)
		{
			for(i=0;i<nElems-1;i+=2)
				if(a[i]>a[i+1])
					swap(i,i+1);
			for(j=1;j<nElems-1;j+=2)
				if(a[j]>a[j+1])
					swap(j,j+1);
			k++;
		}
	}
	private void swap(int one, int two)
	{
		long temp = a[one];
		a[one] = a[two];
		a[two] = temp;
	}
}
class OddEvenSort
{
	public static void main(String[] args)
	{
		int maxSize = 100;
		OddEven arr;
		arr = new OddEven(maxSize);
		arr.insert(77);
		arr.insert(99);
		arr.insert(44);
		arr.insert(55);
		arr.insert(22);
		arr.insert(88);
		arr.insert(11);
		arr.insert(00);
		arr.insert(66);
		arr.insert(33);
		System.out.println("Before Sort : ");
		arr.display();
		arr.oddEvenSort();
		System.out.println("After Sort : ");
		arr.display();
	}
}