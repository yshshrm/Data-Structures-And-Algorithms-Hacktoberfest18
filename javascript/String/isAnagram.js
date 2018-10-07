// Anagram == two words made of the same letters (even the number of letter usages must be equal), not counting spaces

function isAnagram(wordOne, wordTwo){
    return _getWordLetters(wordOne) === _getWordLetters(wordTwo);
}

function _getWordLetters(word){
    return word.split('').sort().join('').trim();
}