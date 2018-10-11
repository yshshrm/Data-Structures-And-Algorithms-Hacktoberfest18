package main

import (
	"fmt"
)

//Principal function that calls merge and divides the array
func mergeSort(v []int)([]int) {
	if (len(v) > 1){
		v1 := v[ :len(v)/2]
		v2 := v[len(v)/2: ]
		v1 = mergeSort(v1)
		v2 = mergeSort(v2)
		v = merge(v1, v2)
	}
	return v
}

//Merge two arrays in one
func merge(a []int, b []int)([]int){
	v := make([]int, len(a)+len(b))
	j := 0
	i := 0
	k := 0
	//Choose the lower number and add to v
	for i < len(a) && j < len(b) {
		if(a[i] < b[j]){
			v[k] = a[i]
			i++
		}else{
			v[k] = b[j]
			j++
		}
		k++
	}

	//The rest of the arrays
	for ; i < len(a); i++ {
		v[k] = a[i]
		k++
	}
	for ; j < len(b); j++ {
		v[k] = b[j]
		k++
	}

	//Returns the concatenated array
	return v
}

func main() {
	vet := []int{1, 200, 0, 0, 87, 10}
	vet2 := mergeSort(vet)
	fmt.Println("Before")
	fmt.Println(vet)
	fmt.Println("After")
	fmt.Println(vet2)

}
