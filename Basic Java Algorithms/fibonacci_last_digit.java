import java.util.*;
public class fibonacci_last_digit
{
	public static void main(String args[])
	{
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		long r=0;
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
			long p=0;
			long c=1;
			for(int i=2;i<=n;i++)
			{
				r=(p+c)%10;
				p=c;
				c=r;
			}
			System.out.print(r);
		}
	}
}
