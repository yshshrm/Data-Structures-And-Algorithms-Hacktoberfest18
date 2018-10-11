const insertionSort = (values) => {
  for (let i = 0; i < values.length; i++) {
    let value = values[i];
    for (let j = i - 1; j > -1 && values[j] > value; j--) {
      values[j + 1] = values[j];
    }

    values[j + 1] = value;
  }

  return values;
}

console.log(insertionSort([99, 238, 0, 11, -2, 1, 19, 0, 11]));
