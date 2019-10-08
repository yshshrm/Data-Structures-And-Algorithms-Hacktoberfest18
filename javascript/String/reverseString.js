function reverse(str) {
    let revd = "";
    for (let letter of str.split('')) {
        revd = letter + revd;
    }
    return revd;
}

function reverseString(str) {
    return str.split('').reverse().join('');
}

function reverseStringRecursion(str) {
    if(str === ''){
        return '';
    } else {
        return reverseStringRecursion(str.substring(1)) + str.charAt(0);
    }
}

function reverseStringLoop(str){
    let result = "";
    for(let i = str.length - 1; i >= 0; i--){
      result += str[i];
    }
    return result;
}

var word = "ocean";
console.log(reverse(word));
console.log(reverseString(word));
console.log(reverseStringRecursion(word));
console.log(reverseStringLoop(word));
