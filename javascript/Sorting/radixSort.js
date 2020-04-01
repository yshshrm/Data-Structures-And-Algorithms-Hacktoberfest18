
/**
 *  Radix Sort
 *  - Define a function that accepts a list of numbers
 *  - Figure out how many digits is the largest number of digits
 *  - Loop from k = 0 up to this largest number of digits
 *  - For each iteration of the loop:
 *      - Create buckets for each digit (0-9)
 *      - place each number in the corresponding bucket based on 
 *          the kth digit
 *  - Replace our existing array with values in our buckets
 *      starting with 0 and going up to 9
 *  - Return the list in the end!
 */

function getDigit(num, i) {
    return Math.floor(Math.abs(num) / Math.pow(10, i)) % 10;
}

function digitCount(num) {
    if(num === 0) return 1;
    return Math.floor(Math.log10(Math.abs(num))) + 1;
}

function mostDigits(nums) {
    let maxDigits = 0;
    for(let i = 0; i < nums.length; i++) {
        maxDigits = Math.max(maxDigits, digitCount(nums[i]));
    }
    return maxDigits;
}

function radixSort(nums) {
    let maxDigitsCount = mostDigits(nums);
    for(let k = 0; k < maxDigitsCount; k++) {
        let digitBuckets = Array.from({length: 10}, () => []);
        for(let i = 0; i < nums.length; i++) {
            let digit = getDigit(nums[i], k);
            digitBuckets[digit].push(nums[i]);
        }
        nums = [].concat(...digitBuckets);
    }
    return nums;
}