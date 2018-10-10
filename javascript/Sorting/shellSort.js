const arrayToSort = [234,544,235,1,4,555,4435,1223,545];
const gaps = [701, 301, 132, 57, 23, 10, 4, 1];
// Mutilates the array so be careful
const shellSort = (array) => {
  for(var g = 0; g < gaps.length; g++) {
    let gap = gaps[g];
    for(var i = gap; i < array.length; i++) {
      var temp = array[i];
      for(var j = i; j >= gap && array[j - gap] > temp; j -= gap) {
        array[j] = array[j - gap];
      }
      array[j] = temp;
    }
  }
  return array;
}

console.log(`Your initial array is: ${arrayToSort}`);
console.log(`After shell sort: ${shellSort(arrayToSort)}`);