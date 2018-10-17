// Given an array, find the minimum and maximum values that can be calculated by a subset of n-1 of the values
function minMaxSum(arr) {
    var i, len, 
        min = [], 
        max = [];

    for( i = 0, len = arr.length; i < len; i++ ) {
        if( i < len -1 ) {
            min.push(arr[i]);   
        }
        
        if( i === 0 ) {
            continue;
        }
        
        max.push(arr[i]);
    }

    return {
        min: min.reduce(function(acc, v) { return acc + v; }),
        max: max.reduce(function(acc, v) { return acc + v; })
    };
}

console.log(minMaxSum([1, 2, 3, 4, 5]));
// {min: 10, max: 14}
