// Function kadane
// Goal: Find the contiguous subarray within a one-dimensional array, a[1...n], of numbers which has the largest sum
// Method: Dynamic Programming
// More info: https://en.wikipedia.org/wiki/Maximum_subarray_problem
function kadane(array) {
  // First we initialise 2 variables the maximum sum of a subarray ending in the position we are
  // and the maximum sum of the best subarray we have found
  // these 2 values correspond to the first element at the start
  let maxEndingHere = array[0];
  let maxSoFar = array[0];
  // We iterate through all the elements in the array
  for(let i = 0; i<array.length; i++) {
    // If the maxEndingHere plus the new element is better than the new element we accumulate the result
    // If not we reset the maxEndingHere to the value of the element
    maxEndingHere = Math.max(array[i], maxEndingHere + array[i])
    // And if the sum of the array ending in the position we are is better than the maximum sum we have found we set
    // the maximum sum to the sum we currently have
    maxSoFar = Math.max(maxEndingHere, maxSoFar);
  }
  // When we have finished the array we return the maximum sum we have found
  return maxSoFar;
}

const example = [1,-3,4,5,-5,1,5,10];
const result = kadane(example);
console.log(result); // 20 which corresponds to the sum of [4,5,-5,1,5,10]