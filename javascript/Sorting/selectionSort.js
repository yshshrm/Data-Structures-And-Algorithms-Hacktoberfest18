function selectionSort(values) {
    for (i = 0; i < values.length; i++) {
        let indexOfMin = i;
        for (let j = i + 1; j < values.length; j++) {
            if (values[j] < values[indexOfMin]){
                indexOfMin = j;
            }
        }

        if (i != indexOfMin ) {
            let temporary = values[i];
            values[i] = values[indexOfMin];
            values[indexOfMin] = temporary;
        }
    }

    return values;
}

console.log(selectionSort([23, 0, 99, -123, 12, 47, 3, 48, -123]));