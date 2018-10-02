import java.util.*;
public class fibonacci
{
	public static void main(String args[])
	{
		int f;
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		f=Fibonacci(n);
		System.out.println(f);
	}
	public static int Fibonacci(int n)
	{
		if(n<=1)
			return n;
		else
			return Fibonacci(n-1)+Fibonacci(n-2);
	}
}
