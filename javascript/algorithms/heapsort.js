const heapSort = (arr) => {
	const n = arr.length;

	for (let i = (n/2 - 1); i >= 0; i--) 
		heapify(arr, n, i);

	for (let i = n-1; i >= 0; i--) {
		let swap = arr[0];
		arr[0] = arr[i];
		arr[i] = swap;
		heapify(arr, i, 0)
	}

	return arr;
}

const heapify = (arr, n, i) => {
	let largest = i, l = 2*i + 1, r = 2*i + 2;

	if(l < n && arr[l] > arr[largest]) 
		largest = l;

	if(r < n && arr[r] > arr[largest]) 
		largest = r;

	if (largest != i) {
		let swap = arr[i];
		arr[i] = arr[largest];
		arr[largest] = swap;
		heapify(arr, n, largest);
	}
}