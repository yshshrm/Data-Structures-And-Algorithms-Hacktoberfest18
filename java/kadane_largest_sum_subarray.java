//This problem helps in finding largest sum of contiguous subarray using KADANE ALGO
import java.io.*;

class kadaneUseCase 
{
    public static int kadaneAlgo(int[] arr)
    {
        int max_sofar=arr[0];
        int maximum=arr[0];
        int i;
        for(i=1;i<arr.length;i++)
        {
            if(max_sofar+arr[i]>arr[i])
                max_sofar=max_sofar+arr[i];
            else
                max_sofar=arr[i];
                
            
            if(max_sofar>maximum)
                maximum=max_sofar;
            
        }
        return maximum;
    }
	public static void main (String[] args) 
	{
		int arr[]={1, 2, 3, -2, 5};
		int ans=kadaneAlgo(arr);
		System.out.println(ans);
	}
}
