import java.util.*;
public class Fibonacci
{
	public static void main(String args[])
	{
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		long c[]=new long[n+1];
		if(n==0)
		{
			System.out.println(0);
		}
		else if(n==1)
		{
			System.out.println(1);
		}
		else
		{
			c[0]=0;
			c[1]=1;
			for(int i=2;i<=n;i++)
				c[i]=c[i-1]+c[i-2];
			System.out.println(c[n]);
		}
	}
}
