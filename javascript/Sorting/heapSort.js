
function swap(values, x, y) {
	let temp = values[x];
	values[x] = values[y];
	values[y] = temp;
}
function heapify(values, n, i) {
	let largest = i;
	const left = 2*i+1;
	const right = 2*i+2;
	if (left < n && values[left] > values[largest]) {
		largest = left;
	}
	if (right < n && values[right] > values[largest]) {
		largest = right;
	}
	if (largest !== i) {
		swap(values, i, largest);
		heapify(values, n, largest);
	}
}
function heapSort(values) {
	const n = values.length;
	for (let i = Math.floor(n/2)-1; i>=0; i--) {
		heapify(values, n, i);
	}
	for (let i=n-1; i>=0; i--) 
    {
        swap(values, 0, i); 
        heapify(values, i, 0); 
    }
    return values;
}

console.log(heapSort([12,11,13,5,2,9]));