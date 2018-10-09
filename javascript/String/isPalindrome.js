function isPalindrome(str){
  var i, len = str.length;
  for(i =0; i<len/2; i++){
    if (str[i]!== str[len -1 -i])
       return false;
  }
  return true;
}

/**
 * determines if a permutation of the given string
 * exists that is a palindrome
 */
function isPermutationPalindrome(str) {
  const letters = {};
  let index = -1;
  
  while ( ++index < str.length ) {
    const c = str.charAt(index);
    
    if (letters[c] !== undefined) delete letters[c];
    else letters[c] = c;
  }
  
  return Object.keys(letters).length < 2;
}
