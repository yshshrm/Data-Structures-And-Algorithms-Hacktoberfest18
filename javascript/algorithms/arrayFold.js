export const arrayFold = (array, foldCenter) => {
    
    if(array.length == 0) { return array; }
    
    var foldedArray = [];
    var fPoint = (array.length-1)/2; 
    
    for(var i=0; i< fPoint; i++){
        var b = array.length -1 - i;
        foldedArray.push(array[i] + array[b]); 
    }

    if(array[fPoint])
    foldedArray.push(array[fPoint]);

    foldCenter--;
    
    if(foldCenter > 0)
        return arrayFold(foldedArray, foldCenter);

    return foldedArray;
};
