import java.util.*;
public class change
{
	private static int getChange(int m)
	{
		int count=0;
		int coins[]={10,5,1};
		for(int i=0;m>0;i++)
		{
			count+=m/coins[i];
			m%=coins[i];
		}
		return count;
	}
	public static void main(String[] args)
	{
		Scanner scanner=new Scanner(System.in);
		int m= scanner.nextInt();
		System.out.println(getChange(m));
	}
}
