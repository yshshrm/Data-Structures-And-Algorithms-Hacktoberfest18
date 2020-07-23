import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		int n,i,j,temp1,temp2,k;
		
		while(t-- >0){
			
			n=sc.nextInt();
			int[] a= new int[n];
			int[]b=new int[n];
		
			for(i=0;i<n;i++){
				a[i]=sc.nextInt();
				b[i]=a[i];
			}
			
			for(i=0;i&lt;n-1;i++)
				for(j=0;j&lt;n-i-1;j++){
					if(a[j]="">a[j+1]){
						temp1=a[j];
						a[j]=a[j+1];
						a[j+1]=temp1;

					}
				}
				
			for(i=0;i<n;i++)
				for(j=0;j&lt;n;j++){
					if(b[i]==a[j])
						system.out.print(j+"="" ");
				}
				
			system.out.println();
		} 
	} 
}