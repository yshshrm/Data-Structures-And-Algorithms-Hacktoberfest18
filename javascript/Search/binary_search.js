// A recursive binary search algorithm.
// It returns location of x in a given array arr[l..r] is present, otherwise -1
const binarySearch = (arr, l, r, x) =>
{
	if (r >= l)
	{
		const mid = Math.floor(l + (r - l) / 2);

		// If the element is present at the middle itself
		if (arr[mid] == x)  return mid;

		// If element is smaller than mid, then it can only be present
		// in left subarray
		if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present in right subarray
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not present in array
	return -1;
}


const search = (arr, x) => {
    return binarySearch(arr, 0, arr.length, x);
}

const arr = [2, 3, 4, 10, 40];
const x = 3;
const result = search(arr, x);
(result == -1) ? console.log("Element is not present in array")
		: console.log("Element is present at index %d \n", result);