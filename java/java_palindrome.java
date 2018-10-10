
public class java_palindrome {
	
	public String isStringAPalindrome(String testString){
		String reverseString = new StringBuilder(testString).reverse();
		if(testString.equals(reverseString)){
			return true;
		}
		return false;
	}

}
