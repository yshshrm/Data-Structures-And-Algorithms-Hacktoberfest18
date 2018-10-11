// Given an integer, write a function that returns true if the given number is palindrome, else false. For example, 12321 is palindrome, but 1451 is not palindrome

const isPalindrome = function(x) {
  if (x < 0) return false;

  let palindrome = x;
  let reverse = 0;
  while (palindrome !== 0) {
    let remainder = palindrome % 10;
    reverse = reverse * 10 + remainder;
    palindrome = palindrome / 10;
    // console.log(palindrome);
  }
  return x === reverse;
};

console.log(isPalindrome(121));
