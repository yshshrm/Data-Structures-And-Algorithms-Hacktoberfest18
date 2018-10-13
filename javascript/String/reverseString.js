function reverse(str) {
  let revd = '';
  for (let letter of str.split('')) {
    revd = letter + revd;
  }
  return revd;
}

var word = 'ocean';
console.log(reverse(word));

const oneLineReverse = str =>
  str
    .split('')
    .reverse()
    .join('');

console.log(oneLineReverse(word));
