const bracketPattern = /[[\](){}]/g;
const bracketPairs = {
  //keeps track of the possible bracket pairings
  '[': ']',
  '(': ')',
  '{': '}',
};
function hasBalancedBrackets(inputString) {
  const inputBrackets = inputString.match(bracketPattern); // returns an array of all the brackets in the input
  const brackets = [];

  // console.log("brackets", brackets)
  if (!inputString.length || !inputBrackets.length) {
    return true; // empty input or no brackets i.e. 'balanced' (throwing an error is fine also)
  }
  inputBrackets.forEach(function(bracket) {
    const lastBracket = brackets[brackets.length - 1];
    console.log('bracket', bracket);
    console.log('bracketPairs[lastBracket]', bracketPairs[lastBracket]);
    console.log('bracket', bracket);
    if (bracketPairs[lastBracket] === bracket) {
      // the current bracket and the last bracket are a pair
      brackets.pop(); // we found a pair so remove the opening bracket from the array and move on
    } else {
      brackets.push(bracket);
    }
    console.log('brackets in loop', brackets);
  });
  return brackets.length === 0; // if the brackets were balanced then we should not have any brackets in the array
}

console.log(hasBalancedBrackets('[][(){}')); // false
console.log(hasBalancedBrackets('({)}')); // false
console.log(hasBalancedBrackets('({[]})')); // true
console.log(hasBalancedBrackets('text ( is allowed ){rwwrwrrww [] ()}')); // true

// Method 2 - Naive Approach
function hasBalancedBrackets(str) {
  let openBrackets = [];
  for (let i = 0; i < str.length; i++) {
    if (str[i] === '(' || str[i] === '[' || str[i] === '{') {
      openBrackets.push(str[i]);
    }
    if (str[i] === ')') {
      if (openBrackets[openBrackets.length - 1] === '(') {
        openBrackets.pop(str[openBrackets.length - 1]);
      } else {
        return false;
      }
    }
    if (str[i] === ']') {
      if (openBrackets[openBrackets.length - 1] === '[') {
        openBrackets.pop(str[openBrackets.length - 1]);
      } else {
        return false;
      }
    }
    if (str[i] === '}') {
      if (openBrackets[openBrackets.length - 1] === '{') {
        openBrackets.pop(str[openBrackets.length - 1]);
      } else {
        return false;
      }
    }
  }
  return openBrackets.length === 0;
}

const result = hasBalancedBrackets('[][(){}');
console.log('result ', result); // false
const result2 = hasBalancedBrackets('({)}');
console.log('result2 ', result2); // false
const result3 = hasBalancedBrackets('({[]})');
console.log('result3 ', result3); // true
