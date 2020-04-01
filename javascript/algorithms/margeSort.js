const margeSort = (arr) => {
	let i = 0, 
		j = 0, 
		result = [],
		left = arr.slice(0, Math.floor(arr.length / 2)), 
		right = arr.slice(Math.floor(arr.length / 2));

	while(i < left.length || j < right.length) {
		if(i === left.length) {
			result.push(right[j]);
			j++
		} else if(j === right.length || left[i] <= right[j]) {
			result.push(left[i]);
			i++
		} else {
			result.push(right[j]);
			j++;
		}
	}

	return result;
}