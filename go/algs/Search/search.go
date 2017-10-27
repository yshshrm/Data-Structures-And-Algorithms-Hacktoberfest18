package algs

func BinarySearch(arr [] int, val int) int {
	return binarySearch(arr, val, 0, len(arr))
}
func binarySearch(arr [] int, val int, low int, high int) int {
	if low <= high {
		middle := low + (high - low) / 2
		if val < arr[middle] {
			return binarySearch(arr, val, 0, middle)
		} else if val > arr[middle] {
			return binarySearch(arr, val, middle + 1, high)
		} else {
			return middle
		}
	}
	return -1
}
func LinearSearch(arr [] int, val int) int {
	for i := 0; i < len(arr); i++ {
		if arr[i] == val {
			return i
		}
	}
	return -1
}