function isStringPalindrome(str) {

    // find the length of a string
    const len = str.length;

    // loop through half of the string
    for (let i = 0; i < len / 2; i++) {
        // check if first and last string are not same
        if (str[i] !== str[len - 1 - i]) {
            return 'It is not a palindrome';
        }
    }

    return 'It is a palindrome';
}

// isStringPalindrome("REVIVER")    result: It is a palindrome
// isStringPalindrome("ABCD")       result: It is not a palindrome
