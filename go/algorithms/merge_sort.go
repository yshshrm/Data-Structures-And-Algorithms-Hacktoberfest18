package main

import "fmt"

var max = int(^uint(0) >> 1)

func Merge(arr []int, left int, middle int, right int) {
	leftSize := middle - left + 1
	rightSize := right - middle
	L := make([]int, leftSize+1)
	for i := 0; i < leftSize; i++ {
		L[i] = arr[left+i]
	}
	R := make([]int, rightSize+1)
	for j := 0; j < rightSize; j++ {
		R[j] = arr[middle+1+j]
	}
	L[leftSize] = max
	R[rightSize] = max
	i := 0
	j := 0
	for k := left; k <= right; k++ {
		if L[i] <= R[j] {
			arr[k] = L[i]
			i++
		} else {
			arr[k] = R[j]
			j++
		}
	}

}

func MergeSort(arr []int, left int, right int) {
	if left < right {
		middle := (left + right) / 2
		MergeSort(arr, left, middle)
		MergeSort(arr, middle+1, right)
		Merge(arr, left, middle, right)
	}
}

func main() {
	var arr = []int{1, 9, 5, 4, 7, 6, 8}
	fmt.Println(arr)
	MergeSort(arr, 0, len(arr)-1)
	fmt.Println(arr)
}
