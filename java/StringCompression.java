/*

    1.6 String Compression

    Implement a method to perform basic string compression using the counts
    of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the
    "compressed" string would not become smaller than the original string, your method should return
    the original string. You can assume the string has only uppercase and lowercase letters (a - z).

 */

package code.arraysandstrings;

public class StringCompression {
    public static String stringCompression(String originalStr) {
        int strLen = originalStr.length();

        // Strings less than length 3 will never be compressed smaller than original
        // so return early if length is 2 or less.
        if (strLen <= 2) {
            return originalStr;
        }

        int count = 1;
        char charPtr = originalStr.charAt(0);

        StringBuilder compressedStr = new StringBuilder();

        for (int i = 1; i < strLen; i++) {
            if (originalStr.charAt(i) != originalStr.charAt(i - 1)) {
                compressedStr.append(charPtr);
                compressedStr.append(count);

                charPtr = originalStr.charAt(i);
                count = 1;
            } else {
                count++;
            }
        }

        compressedStr.append(charPtr);
        compressedStr.append(count);

        if (compressedStr.length() >= originalStr.length()) {
            return originalStr;
        }

        return compressedStr.toString();
    }
}
