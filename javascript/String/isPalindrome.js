function isPalindrome(str){
  var i, len = str.length;
  for(i =0; i<len/2; i++){
    if (str[i]!== str[len -1 -i])
       return false;
  }
  return true;
}

function isPalindrome2(str) {
  var original = str.split('');
  var reversed = str.split('').reverse();
  return original.every(function(ch, index){
    return reversed[index] === ch;
  });
}