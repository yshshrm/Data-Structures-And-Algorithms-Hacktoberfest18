const quickSort = (arr) => {
	if (arr.length <= 1) {
		return arr;
	} else {
		let left = [], 
			right = [], 
			newArray = [], 
			pivotPoint = arr.pop();

		for(let i = 0; i < arr.length; i++) {
			arr[i] <= pivotPoint ? left.push(arr[i]) : right.push(arr[i]);
		}

		return newArray.concat(quickSort(left), pivotPoint, quickSort(right));
	}
}