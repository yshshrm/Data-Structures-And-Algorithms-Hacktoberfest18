const binarySearch = (arr, el) => {
    let beg = 0;
    let end = arr.length - 1;
    while(end >= beg){
        let mid = Math.floor((end + beg) / 2);
        if(arr[mid] === el) return mid;
        else if(arr[mid] < el) beg = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

let sortedArray = [2,3,5,6,7,8,10,20,28,30,49,56,67,80];
console.log("Pos of 10: " + binarySearch(sortedArray, 10));