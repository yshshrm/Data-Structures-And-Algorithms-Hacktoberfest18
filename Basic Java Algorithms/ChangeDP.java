import java.util.*;
public class ChangeDP
{
	static int minCoins(int coins[], int m, int V)
    {
       if (V == 0) return 0;
       int res = Integer.MAX_VALUE;
       for (int i=0; i<m; i++)
       {
         if (coins[i] <= V)
         {
             int sub_res = minCoins(coins, m, V-coins[i]);
             if (sub_res != Integer.MAX_VALUE && sub_res + 1 < res)
                res = sub_res + 1;
         }
       }
       return res;
    }
	public static void main(String[] args)
	{
		int arr[]={1,3,4};
		int m=arr.length;
		Scanner scanner=new Scanner(System.in);
		int n= scanner.nextInt();
		System.out.println(minCoins(arr,m,n));
	}
}
