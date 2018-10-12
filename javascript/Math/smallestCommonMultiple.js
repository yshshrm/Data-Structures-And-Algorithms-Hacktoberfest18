/**
 * Finds the smallest common multiple of the provided parameters that can be evenly divided by both,
 * as well as by all sequential numbers in the range between these parameters.
 */

function smallestCommons(arr) {
  // Sort arr
  arr.sort(function (a, b) {
    return b - a;
  });
  // Make array with all numbers in the range (inclusive)
  var rangeArr = [];
  for (var i = arr[0]; i >= arr[1]; i--) {
    rangeArr.push(i);
  }
  // Loop through the range, find the lcm by incrementing the multiplier until all numbers are divisible
  var multiplier = 1;
  var n = 0;
  do {
    if ((arr[0] * multiplier) % rangeArr[n] !== 0) {
      multiplier++;
      n = 0;
    } else {
      n++;
    }
  } while (n < rangeArr.length);
  return multiplier * arr[0];
}
// Examples
smallestCommons([1, 5]); // returns a number
smallestCommons([1, 5]); // returns 60
smallestCommons([5, 1]); // returns 60
smallestCommons([1, 13]); // returns 360360
smallestCommons([23, 18]); // returns 6056820