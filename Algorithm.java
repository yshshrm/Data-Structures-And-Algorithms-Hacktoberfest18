public class Java_Algorithm {
	
	public String isStringAlgorithm(String testString){
		String reverseString = new StringBuilder(testString).reverse();
		if(testString.equals(reverseString)){
			return true;
		}
		return false;
	}

}
