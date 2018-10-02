function bubbleSort(values) {
  for (let i = values.length - 1; i >= 0; i--) {
    for(var j = 1; j <= i; j++) {
      if(values[j - 1] > values[j]) {
           let temporary = values[j - 1];
           values[j - 1] = values[j];
           values[j] = temporary;
        }
     }
   }
   return values;
}

console.log(bubbleSort([93, 2, 82, 44, 210, 1, 39])); 