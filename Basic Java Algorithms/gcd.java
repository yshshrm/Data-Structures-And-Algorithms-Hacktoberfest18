import java.util.*;
public class gcd
{
	public static void main(String args[])
	{
		int i;
		Scanner in=new Scanner(System.in);
		int a=in.nextInt();
		int b=in.nextInt();
		i=euclid(a,b);
		System.out.println(i);
	}
	public static int euclid(int a,int b)
	{
		int c;
		if(b==0)
			return a;
		else
		{
			c=a%b;
			return euclid(b,c);
		}
	}
}
