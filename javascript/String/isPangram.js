const isPangram = function (string) {

    let stringArr = string.toLowerCase().split('');
    let pangram = {};
    for (let char of stringArr) {
        if (pangram[char] === undefined) {
            pangram[char] = 1;
        } else {
            pangram[char]++;
        }
    }

    let start = "a".charCodeAt(0),
        end = "z".charCodeAt(0);
    for (let i = start; i <= end; i++) {
        if (pangram[String.fromCharCode(i)] === undefined) {
            return false;
        }
    }
    return true;
}