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

var word = "ocean";
console.log(reverse(word));
console.log(reverseString(word));
console.log(reverseStringRecursion(word));