package main

import "fmt"

func InsertionSort(items []int) {
    var len = len(items)
	
    for i := 1; i < len; i++ {
        j := i
		
        for j > 0 {
            if items[j-1] > items[j] {
                items[j-1], items[j] = items[j], items[j-1]
            }
            j -= 1
        }
    }
}

func main() {
	var a = []int{3, 1, 7, 6, 9, 2, 5, 4, 8}

	fmt.Println("Unsorted array: ", a)
	InsertionSort(a)
	fmt.Println("Sorted array: ", a)
}
