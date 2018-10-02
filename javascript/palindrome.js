function palindrome(str) {
    let revdWord = "";
    for (let letter of str) {
        revdWord = letter + revdWord;
    }
    return str === revdWord;
}

console.log(palindrome("kayak")); // expected true
console.log(palindrome("meow")); // expected false