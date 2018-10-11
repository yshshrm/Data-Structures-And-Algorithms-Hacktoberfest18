const quicksort = (startArray) => {
    if (startArray.length <= 1) {
        return startArray;
    } else {

        let left = [];
        let right = [];
        let newArray = [];
        let pivot = startArray.pop();
        let length = startArray.length;

        for (let i = 0; i < length; i++) {
            if (startArray[i] <= pivot) {
                left.push(startArray[i]);
            } else {
                right.push(startArray[i]);
            }
        }

        return newArray.concat(quicksort(left), pivot, quicksort(right));
    }
}

let testArray = [-2, -12, 13, -17 - 20, -16, 8, 11];

console.log("Starting array: " + testArray);
let sortedArray = quicksort(testArray);
console.log("Quick-sorted array: " + sortedArray);