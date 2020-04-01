import java.util.*;
public class Main {
    public static void main(String args[]) {
        	
		Scanner s = new Scanner(System.in);
		int nos=s.nextInt();
		int noc=s.nextInt();
		
		
		int[] stalls=new int[nos];
		for(int i=0;i<nos;i++)
		{
			stalls[i]=s.nextInt();
		}
		Arrays.sort(stalls);
		int finans=0;
		int in=0;
		int fin=stalls[stalls.length-1]-stalls[0];
		while(in<=fin)
		{
		int mid =(in+fin)/2;
		if(ispossible(stalls,noc,mid))
		{
			in=mid+1;
			finans=mid;
			
		}
		else
		{
			fin=mid-1;
		}
		
		}
		System.out.println(finans);
		
	}

	public static boolean ispossible(int[] stall,int noc,int mid)
	{
		int cplaced=1;
		int pos=stall[0];
		
	for(int i=0;i<stall.length;i++)
	{
		if(stall[i]-pos>=mid)
		{
			cplaced++;
			pos=stall[i];
		
			if(noc==cplaced)
			{
				return true;
			}
		}

	}
	return false;

    }
}
