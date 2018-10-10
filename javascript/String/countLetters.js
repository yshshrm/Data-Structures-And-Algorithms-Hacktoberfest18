// FIXME: Consider diacritics
function countVowels(input) {
  if (typeof input !== 'string') return 0
  let count = 0;
  for (let i = 0; i < input.length; i++)
    if (/[aeiou]/i.test(input.charAt(i)))
      count++;
  return count;
}

console.log('Four has', countVowels('four 😅'), 'vowels');
