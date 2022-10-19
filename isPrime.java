import java.util.*;
public class Main{
  public static void main(String args[]){
  
     System.out.println("Enter a Number:"); 
     Scanner sc = new Scanner(System.in);
     int n = sc.nextInt();
     if(isPrimeNumber(n)==true)
      System.out.println(n+" is a Prime Number");
     else
      System.out.println(n+" is  not a Prime Number");
 }
  
static boolean isPrimeNumber(int n) {
    if (n<2)
	return false;	    
    if (n==2)
	return true;
    for(int i=3;i*i<=n;i+=2) {
        if(n%i==0)
            return false;
    }
    return true;
}
}

