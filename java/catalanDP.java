/*
Author: dvlpsh
Description: nth Catalan Number that can be used to calculate number of distinct BSTs that can be constructed. This is a Recursive implementation.
*/
import java.io.*;
import java.util.*;


class catalanDP
{
	public static void main(String args[])throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		System.out.println("Enter the number of nodes in the Binary Search Tree:");
		int n = Integer.parseInt(br.readLine());
		
		int T[] = new int[n+1];
		T[0]=T[1]=1;
		//catalan number DP
		
		for(int i=2;i<=n;i++)
			for(int j=0;j<i;j++)
				T[i]+=T[j]*T[i-j-1]; //DP Recurrence
				
		System.out.println(T[n]);
		
	}
}




