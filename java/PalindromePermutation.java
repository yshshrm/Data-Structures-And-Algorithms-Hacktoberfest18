/*

    1.4 Palindrome Permutation

    Given a string, write a function to check if it is a permutation of a palindrome.
    A palindrome is a word or phrase that is the same forwards and backwards. A permutation
    is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

 */

package code.arraysandstrings;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

public class PalindromePermutation {
    public static boolean palindromePermutation(String str) {
        Map<Character, Integer> charCount = new HashMap<>();

        // Given example ignores spaces, so skip spaces
        for (char c : str.toCharArray()) {
            if (c == ' ') {
                continue;
            }

            char lowercaseChar = Character.toLowerCase(c);

            if (!charCount.containsKey(lowercaseChar)) {
                charCount.put(lowercaseChar, 1);
            } else {
                charCount.put(lowercaseChar, charCount.get(lowercaseChar) + 1);
            }
        }

        // There should be at most one odd character (if the string length minus spaces is odd)
        // Anything above one oddCount will not be a palindrome
        return foundMoreThanOneOdd(charCount.values());
    }

    private static boolean foundMoreThanOneOdd(Collection<Integer> charCount) {
        int oddCount = 0;

        for (int count : charCount) {
            if (isOdd(count)) {
                oddCount++;
            }
        }

        return oddCount < 2;
    }

    private static boolean isOdd(int num) {
        return num % 2 != 0;
    }
}
