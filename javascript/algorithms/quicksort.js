function quicksort(startArray) {
    if (startArray.length <= 1) {
        return startArray;
    } else {

        var left = [];
        var right = [];
        var newArray = [];
        var pivot = startArray.pop();
        var length = startArray.length;

        for (var i = 0; i < length; i++) {
            if (startArray[i] <= pivot) {
                left.push(startArray[i]);
            } else {
                right.push(startArray[i]);
            }
        }

        return newArray.concat(quicksort(left), pivot, quicksort(right));
    }
}

var testArray = [-2, -12, 13, -17 - 20, -16, 8, 11];

console.log("Starting array: " + testArray);
var sortedArray = quicksort(testArray);
console.log("Quick-sorted array: " + sortedArray);