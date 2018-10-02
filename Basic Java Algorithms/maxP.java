import java.util.*;
public class maxP
{
	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		int n=in.nextInt();
		long[] arr=new long[n];
		for(int i=0;i<n;i++)
		{
			arr[i]=in.nextInt();
		}
		Arrays.sort(arr);
		System.out.println(arr[n-1]*arr[n-2]);
	}
}
