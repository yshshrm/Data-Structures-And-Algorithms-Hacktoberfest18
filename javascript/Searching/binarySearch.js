function binarySearch(arr, el){
    var beg = 0;
    var end = arr.length - 1;
    while(end >= beg){
        var mid = Math.floor((end + beg) / 2);
        if(arr[mid] === el) return mid;
        else if(arr[mid] < el) beg = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

var sortedArray = [2,3,5,6,7,8,10,20,28,30,49,56,67,80];
console.log("Pos of 10: " + binarySearch(sortedArray, 10));