// Counting sort is useful when numbers fall in a known range
// It has a time complexity of O(N + K) where K is the size of the range and n is the size of the array
// It works by counting the instances of each of the values within K then reassembling an output array in order
const countSort = (arr, k) => {
  // instantiate a counts with slots up to K
  const counts = new Array(k + 1).fill(0);
  // count all of the instances of each number in arr
  arr.forEach(num => {
    counts[num] += 1;
  })
  
  // go back through the counts array to build an output array
  return counts.reduce((acc, count, i) => {
    // ignore values that did not appear in arr
    if (count === 0) return acc;
   
    for(let j = 0; j < count; j++){
      acc.push(i);
    }
   return acc;
   }, []);
}
