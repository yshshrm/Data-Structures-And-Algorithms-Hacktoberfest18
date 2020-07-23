// Java program to illustrate the 
// Java.lang.Integer.numberOfTrailingZeros() method 
import java.lang.*; 

public class TrailingZeros { 

public static void main(String[] args) { 

	int a = 155; 
	System.out.println("Integral Number = " + a); 


	// Returns the number of zero bits following the lowest-order 
		//rightmost one-bit 
	System.out.print("Number of Trailing Zeros = "); 
	System.out.println(Integer.numberOfTrailingZeros(a)); 
		a = 24; 
	System.out.println("Integral Number = " + a); 


	// Returns the number of zero bits following the lowest-order 
	//rightmost one-bit 
	System.out.print("Number of Trailing Zeros = "); 
	System.out.println(Integer.numberOfTrailingZeros(a)); 
	
} 
} 
