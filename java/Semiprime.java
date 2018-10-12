import java.util.Scanner;

public class Semiprime {

	
		 static int checkSemiprime(int num) 
		    { 
		        int cnt = 0; 
		      
		        for (int i = 2; cnt < 2 &&  
		                     i * i <= num; 
		        		++i) 
		                       
		            while (num % i == 0){ 
		                num /= i;
		                ++cnt; 
		                } 
		      
		        if (num > 1) 
		            ++cnt; 
		     
		        return cnt == 2 ? 1 : 0; 
		    } 
		    static void semiprime(int n) 
		    { 
		        if (checkSemiprime(n) != 0) 
		            System.out.printf("True\n"); 
		        else
		            System.out.printf("False\n"); 
		    } 
		    public static void main(String[] args) 
		    { 
		    	Scanner sc= new Scanner(System.in);
		        int n = sc.nextInt(); 
		        semiprime(n);    
		    
		    }
}
