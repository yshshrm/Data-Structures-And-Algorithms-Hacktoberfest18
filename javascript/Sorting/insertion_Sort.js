//insertion sort example for an array which elements are integers
function insertionSort (arr) {
    for (let i = 1; i<arr.length; i++){
        for (let j = 0; j>arr.length-1; j++){
            if (arr[i] < arr[j]){
                swap(arr)
            }
        }
    }
    return arr;
}
//swapping function if condition true
function swap (arr) {
    let temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}



//test array
let arr = [5, 4, 3, 2, 1]
console.log(insertionSort(arr))