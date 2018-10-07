function sumPrimes(num) {  // sum of all primes upto and including num
  
  let arr = [];

  for(let i = 2, j = 2; i <= num; i++, j++) {  // fill up these arr with all numbers from 2 to num
  	arr.push(i);
  }

  let primes = arr.slice();

  // Below: for each number in "arr", we eliminate all its multiples in "primes", hence only the prime numbers will be left in "primes".

  arr.forEach(num => {
  	primes = primes.filter(number => !(Number.isInteger(number / num) && Math.round(number / num >= 2)));  //Using Sieve method to generate primes
  });

  // sum the "primes" array;
  return primes.reduce((a, x) => a + x, 0);
}
