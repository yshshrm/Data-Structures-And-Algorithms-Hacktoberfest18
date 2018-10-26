function reverseArray(array){
    var reverse = new Array;
    for (var i=0;i<array.length; i++){
        reverse[array.length-1-i]=array[i];

    }
    return reverse;
}
