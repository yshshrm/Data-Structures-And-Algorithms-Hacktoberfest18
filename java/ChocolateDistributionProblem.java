import java.lang.*;
import java.io.*;

class Mohit {
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	public static int GetInt() throws IOException
	{
	    return Integer.parseInt(br.readLine());
	}
	public static String[] GetArray() throws IOException
	{
	    return br.readLine().split(" ");
	}
	public static void main (String[] args) throws java.lang.Exception {
		int t=GetInt();
	    StringBuilder sb=new StringBuilder();
		while(t-->0)
		{
            int n=GetInt();
            String sarr[]=GetArray();
            int arr[]=new int[n];
            int no=GetInt();
            for(int i=0; i<n; i++)
            {
                arr[i]=Integer.parseInt(sarr[i]);
            }
            Arrays.sort(arr);
            int min=Integer.MAX_VALUE;
            for(int i=0; i<=n-no; i++)
            {
                int temp=arr[i+no-1]-arr[i];
                if(temp<min) min=temp;
            }
            sb.append(min).append("\n");
		}
		System.out.println(sb);
	}
}
