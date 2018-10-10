function capitalizeEveryWord(str) {
    const cappedWords = [];
    for (let word of str.split(' ')) {
        cappedWords.push(word[0].toUpperCase() + word.slice(1));
    }
    return cappedWords.join(' ');
}
  
console.log(capitalizeEveryWord("i love cats")); //returns "I Love Cats"