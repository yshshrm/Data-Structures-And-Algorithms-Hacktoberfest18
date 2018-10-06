
public class java_palindrome {
	
	public boolean isStringAPalindrome(String testString){
		String reverseString = new StringBuilder(testString).reverse();
		if(testString.equals(reverseString)){
			return true;
		}
		return false;
	}

}
