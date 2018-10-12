/*

    1.5 One Away

    There are three types of edits that can be performed on strings: insert a character,
    remove a character, or replace a character. Given two strings, write a function to check if they are
    one edit (or zero edits) away.

 */

package code.arraysandstrings;

import java.util.HashMap;
import java.util.Map;

public class OneAway {
    public static boolean oneAway(String string1, String string2) {
        int str1Len = string1.length();
        int str2Len = string2.length();

        // Immediately return if the length of the strings differs more than 1
        if (Math.abs(str1Len - str2Len) > 1) {
            return false;
        }

        if (str1Len > str2Len) {
            return lessThanOneCorrectionNeeded(string1, string2);
        }

        return lessThanOneCorrectionNeeded(string2, string1);
    }

    private static Map<Character, Integer> mapChars(String str) {
        Map<Character, Integer> charMap = new HashMap<>();

        for (char c : str.toCharArray()) {
            if (!charMap.containsKey(c)) {
                charMap.put(c, 1);
            } else {
                charMap.put(c, charMap.get(c) + 1);
            }
        }

        return charMap;
    }

    private static boolean lessThanOneCorrectionNeeded(String longerString, String smallerString) {
        Map<Character, Integer> charMap = mapChars(longerString);
        int correctionsNeeded = 0;
        int editsNeeded = 0;

        for (char c : smallerString.toCharArray()) {
            if (!charMap.containsKey(c) || charMap.get(c) <= 0) {
                editsNeeded++;
                correctionsNeeded++;
            } else {
                charMap.put(c, charMap.get(c) - 1);
            }
        }

        for (int count : charMap.values()) {
            correctionsNeeded += count;
        }

        // Subtract editsNeeded as to not double count chars that weren't found from the second string
        return (correctionsNeeded - editsNeeded) < 2;
    }

}
