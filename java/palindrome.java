
public class java_palindrome {
	
	static boolean isStringAPalindrome(StringBuffer user_input){
		StringBuffer reverseString = new StringBuffer(user_input).reverse();
		if(user_input.equals(reverseString)){
			return true;
		}
		return false;
	}

}
