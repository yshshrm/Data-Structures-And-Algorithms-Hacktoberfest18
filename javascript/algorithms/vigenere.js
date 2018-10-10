"use strict";

const ALPHABET_SIZE = 26

let isAlpha = c => c.match(/^[a-zA-Z]+$/i);
let isUpper = c => c === c.toUpperCase();
let mod = (n, m) => ((n % m) + m) % m; // js modulo bug for negative numbers

let A = 'A'.charCodeAt();
let a = 'a'.charCodeAt();

function vigenere(plain, k) {

    if (!isAlpha(k)) {
        return "Provided [k] must be all alpha";
    }

    // k must be lower case
    k = k.toLowerCase();
    let kLenght = k.length;

    let cipher = [];

    // j will be the index for the k string
    for (let i = 0, j = 0; i < plain.length; i++) {
        const c = plain[i];

        if (isAlpha(c)) {

            // Get Ascii value of char and key
            let cVal = c.charCodeAt();
            let kVal = k[j].charCodeAt() - a;

            if (isUpper(c)) {
                cipher.push(String.fromCharCode(A + ((cVal + kVal) - A) % ALPHABET_SIZE));
            } else {
                cipher.push(String.fromCharCode(a + ((cVal + kVal) - a) % ALPHABET_SIZE));
            }

            j++;
        } else {
            cipher.push(c);
        }

        // loop back the key when j reaches the end
        j = j % kLenght;
    }

    // Concat array and replace ','
    return cipher.toString().replace(/,/g, '');
}


console.log(vigenere("abc", "a3a") === "Provided [k] must be all alpha");
console.log(vigenere("a", "b"))
console.log(vigenere("TOBEO RNOTT OBETH ATIST HEQUE STION", "RELATIONSRELATIONSRELATIONSREL") === "KSMEH ZBBLK SMEMP OGAJX SEJCS FLZSY")