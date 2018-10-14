import java.util.Scanner;
class PalindromeCheck {
	public static void main (String args[]) {
		System.out.print ("Enter a number: ");
		int num = new Scanner(System.in).nextInt();
		
		if (checkPalindrome(num))
			System.out.println("It is a palindrome!");
		else
			System.out.println("It is not a palindrome.");
	}
	
	private static boolean checkPalindrome(int n) {
		String reverse = ""; // To store the reversed number
		String number = Integer.toString(n);
		
		for (int i = number.length() - 1; i >= 0; i--) {
			reverse += number.charAt(i);
		}
		
		if (reverse.equals(number))
			return true;
		else
			return false;
	}
}