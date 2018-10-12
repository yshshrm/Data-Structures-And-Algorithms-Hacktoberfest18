import java.io.*;

public class XorEncryption{
	private static String encryptDecrypt(String input) {
		//Array key can be any length and any chars
		char[] key = {'H', 'a', 'c', 'k', 'F', 'e', 's', 't'}; 
		StringBuilder output = new StringBuilder();
		
		for(int i = 0; i < input.length(); i++) {
			output.append((char) (input.charAt(i) ^ key[i % key.length]));
		}

		return output.toString();
	}
	
	public static void main(String[] args) {
		String str = "contributions";
		String encrypted = "";
		String encCharToDec = "";
		String decryptedStr = "";
		
		System.out.println("Plain text: " + str);
		
		encrypted = XorEncryption.encryptDecrypt(str);
		System.out.println("Cipher text: ".concat(encrypted));

		for(int i = 0; i < encrypted.length(); i++){
			encCharToDec += (int) encrypted.charAt(i) + " ";
		}			
	  System.out.println("Cipher text in decimal: " + encCharToDec);
		
		decryptedStr = XorEncryption.encryptDecrypt(encrypted);
		System.out.println("Decrypted message: " + decryptedStr);
	}
}