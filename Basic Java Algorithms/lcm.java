import java.util.*;
public class lcm
{
	public static void main(String args[])
	{
		long i;
		Scanner in=new Scanner(System.in);
		long a=in.nextLong();
		long b=in.nextLong();
		i=lcm(a,b);
		System.out.println(i);
	}
	public static long euclid(long a,long b)
	{
		long c;
		if(b==0)
			return a;
		else
		{
			c=a%b;
			return euclid(b,c);
		}
	}
	public static long lcm(long a,long b)
	{
		if(a==0 && b==0)
			return 0;
		else
			return (a * b) / euclid(a, b); 
	}
}
