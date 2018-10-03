"use strict";

const ALPHABET_SIZE = 26

let isAlpha = c => c.match(/^[a-zA-Z]+$/i);
let isUpper = c => c === c.toUpperCase();
let mod = (n, m) => ((n % m) + m) % m; // js modulo bug for negative numbers

let A = 'A'.charCodeAt();
let a = 'a'.charCodeAt();

function caesar(plain, k) {

    // k can not be bigger than the length of the alphabet alphabet
    k = mod(k, ALPHABET_SIZE);

    let cipher = [];

    for (let i = 0; i < plain.length; i++) {
        const c = plain[i];

        // Check if character is alpha
        if (isAlpha(c)) {

            // Get Ascii value of char
            let cVal = c.charCodeAt();

            if (isUpper(c)) {
                cipher.push(String.fromCharCode(A + ((cVal + k) - A) % ALPHABET_SIZE));
            } else {
                cipher.push(String.fromCharCode(a + ((cVal + k) - a) % ALPHABET_SIZE));
            }
        } else {
            cipher.push(c);
        }
    }

    // Concat array and replace ','
    return cipher.toString().replace(/,/g, '');
}

console.log(caesar('a', 1) === 'b')
console.log(caesar('3a2', 1) === '3b2')
console.log(caesar('3`a{}2', 1) === '3`b{}2')
console.log(caesar("abcdefghijklmnopqrstuvwxyz", -1) === "zabcdefghijklmnopqrstuvwxy");
console.log(caesar("abcdefghijklmnopqrstuvwxyz", 1) === "bcdefghijklmnopqrstuvwxyza");