function findLongestWordLength(str) {
  //split the string
  str = str.split(' ');
  //create an empty function
  let longest = 0;
  //create for loop
  for (var i = 0; i < str.length; i++) {
    //check to see if word is longer
    if (longest < str[i].length) {
      longest = str[i].length;
    }
  }
  return longest;
}

findLongestWordLength('The quick brown fox jumped over the lazy dog');
