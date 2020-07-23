import java.util.*;
import java.io.*;
import java.math.*;
import java.lang.*;

public class Main{
	public static void main(String args[]) throws java.lang.Exception{
		int t;
		Scanner sc = new Scanner(System.in);
		t = sc.nextInt();
		while(t!=0){
			long ts,js, tomCount, jerryCount, result=0;
			ts = sc.nextLong();
			
			if(ts%2!=0){
				if(ts==1)
					System.out.println(0);
            else
                System.out.println(ts/2);
			} else {
				js =2;
				while(js<=ts){
					tomCount = Long.numberOfTrailingZeros(ts);
					jerryCount = Long.numberOfTrailingZeros(js);
					//System.out.println(tomCount+"\t"+jerryCount);
					
					if(jerryCount > tomCount)
						result++;
					
					js+=2;
				}
				System.out.println(result);
			}
			t--;
		}
	}
}