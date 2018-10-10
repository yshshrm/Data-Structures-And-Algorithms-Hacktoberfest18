const quicksort = startArray => {
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

const testArray = [-2, -12, 13, -17 - 20, -16, 8, 11];

const testQuickSort = (arr) => new Promise((resolve, reject) => {
    if (arr) {
        console.log("Starting array: " + testArray);
        resolve(arr)
    } else {
        reject("there was some problem...")
    }
})

testQuickSort(testArray).then(res => {
    sorted = quicksort(res)
    console.log(`Sorted array: ${sorted}`)
    return res
})
 