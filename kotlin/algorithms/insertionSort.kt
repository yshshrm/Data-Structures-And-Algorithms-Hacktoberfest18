 fun inserttionSort(arr: Array<Long>) : Array<Long>{
    for (j in 1..arr.size - 1){
        var i = j - 1;
        val processedVal = arr[j];
        while ( (i >= 0) && (arr[i] > processedVal) ){
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = processedVal;
    }
    return arr;
}