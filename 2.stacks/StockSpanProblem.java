
import java.util.*;
import java.lang.*;
import java.io.*;

class StockSpanProblem{
    static class pair{
		int data;
		int index;
		public pair(int x,int i) {
			data=x;
			index=i;
		}
	}
	public static void main (String[] args) {
	    Scanner sc=new Scanner(System.in);
	
	
		int t=sc.nextInt();
		while(t-->0) {
		    	Stack<pair> s2=new Stack<>();
		    		ArrayList<Integer> left=new ArrayList<>();
	
		int le=sc.nextInt();
		int arr[]=new int[le];
		for(int i=0;i<le;i++) {
			arr[i]=sc.nextInt();
		}
	   
		  for(int i=0;i<le;i++){
		        if(s2.empty()){
		            left.add(-1);
		            s2.push(new pair(arr[i],i));
		        }else if(s2.size()>0 && s2.peek().data>arr[i]){
		            left.add(s2.peek().index);
		            s2.push(new pair(arr[i],i));
		        }else if(s2.size()>0 && s2.peek().data<=arr[i]){
		           while(s2.size()>0 && s2.peek().data<=arr[i]){
		               s2.pop();
		           }
		           if(s2.size()==0){
		               left.add(-1);
		               s2.push(new pair(arr[i],i));
		           }else{
		               left.add(s2.peek().index);
		               s2.push(new pair(arr[i],i));
		           }
		        }
		    }
		    for(int i=0;i<le;i++){
		        System.out.print(i-left.get(i)+" ");
		    }
		    System.out.println();
	}
	}
}
