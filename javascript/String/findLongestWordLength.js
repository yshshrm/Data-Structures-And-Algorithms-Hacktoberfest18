function findLongestWordLength(str) {
  return str.split(' ').reduce((longest, word)=>{
    if (word.length > longest.length) {
      longest = word;
    }
    return longest;
  }, '').length;
}

findLongestWordLength("The quick brown fox jumped over the lazy dog");