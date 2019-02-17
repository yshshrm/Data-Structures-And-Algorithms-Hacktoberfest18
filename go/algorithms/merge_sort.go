package main

import "fmt"

func mergeSort(arr []int32) []int32 {
	sort(arr, 0, len(arr)-1)

	return arr
}

func sort(arr []int32, lo, hi int) {
	if lo >= hi {
		return
	}

	mid := (lo + hi) / 2
	sort(arr, 0, mid)
	sort(arr, mid+1, hi)
	merge(arr, lo, mid, hi)
}

func merge(arr []int32, lo, mid, hi int) {
	temp := make([]int32, hi-lo+1)
	i, j, k := lo, mid+1, 0

	for i <= mid && j <= hi {
		if arr[i] < arr[j] {
			temp[k] = arr[i]
			i++
		} else {
			temp[k] = arr[j]
			j++
		}

		k++
	}

	for i <= mid {
		temp[k] = arr[i]
		i++
		k++
	}

	for j <= hi {
		temp[k] = arr[j]
		j++
		k++
	}

	for idx := 0; idx < len(temp); idx++ {
		arr[lo] = temp[idx]
		lo++
	}
}

func main() {
	fmt.Println(mergeSort([]int32{3, 1, 2, 5, 6, 8, 9}))
	fmt.Println(mergeSort([]int32{7, 6, 5, 4, 3, 2, 1}))
	fmt.Println(mergeSort([]int32{1, 2, 3, 4, 5, 6, 7}))
}
