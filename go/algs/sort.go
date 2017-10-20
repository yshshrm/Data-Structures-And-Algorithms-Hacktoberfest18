package algs


func BubbleSort(array [] int) {
	for i := 0; i < len(array) - 1; i++ {
		for j := i + 1; j < len(array); j++ {
			if array[i] > array[j] {
				swap(array, i, j)
			}
		}
	}
}

func SelectionSort(array [] int) {
	for i := 0; i < len(array) - 1; i++ {
		var min = i
		for j := i; j < len(array); j++ {
			if array[j] < array[min] {
				min = j
			}
		}
		swap(array, i, min)
	}
}

func InsertionSort(array [] int) {
	for i := 1; i < len(array); i++ {
		var min = i - 1
		for min >= 0 && array[min] > array[min + 1] {
			swap(array, min, min + 1)
			min--
		}
	}
}

func CountingSort(array [] int) {
	max := 0
	for i := 1; i < len(array); i++ {
		if array[i] > max {
			max = array[i]
		}
	}
	storage := make([]int, max)
	for i := 1; i < len(array); i++ {
		storage[i]++
	}
	counter := 0
	for i := 0; i < len(storage); i++ {
		for j := 0; j < storage[i]; j++ {
			array[counter] = i
			counter++
		}
	}
}

func QuickSort(array [] int) {
	quickSort(array, 0, len(array) - 1)
}
func quickSort(array [] int, low int, high int) {
	if low < high {
		partition := partition(array, low, high)
		quickSort(array, low, partition - 1)
		quickSort(array, partition + 1, high)
	}
}
func partition(array []int, low int, high int) int {
	pivot := array[high]
	partition := low
	for i := low; i < high; i++ {
		if array[i] <= pivot {
			swap(array, i, partition)
			partition++
		}
	}
	swap(array, partition, high)
	return partition
}
func part(array [] int, low int, high int) int {
	pivot := array[high]
	part := low
	for i := low; i < high; i++ {
		if array[i] <= pivot {
			swap(array,i,part)
			part++
		}
	}
	swap(array, part, high)
	return part
}


func MergeSort(array [] int) {
	mergeSort(array, 0, len(array) - 1)
}
func mergeSort(array [] int, low int, high int) {
	if low < high {
		pivot := low + (high - low) / 2
		mergeSort(array, low, pivot)
		mergeSort(array, pivot + 1, high)
		merge(array, low, pivot, high)
	}
}
func merge(array [] int, low int, middle int, high int) {
	storage := make([] int, len(array))
	copy(storage, array)
	i := low
	j := middle + 1
	k := low
	for i <= middle && j <= high {
		if storage[i] <= storage[j] {
			array[k] = storage[i]
			i++
		} else {
			array[k] = storage[j]
			j++
		}
		k++
	}
	for i <= middle {
		array[k] = storage[i]
		k++
		i++
	}
}

func swap(array [] int, aIndex int, bIndex int) {
	array[aIndex], array[bIndex] = array[bIndex], array[aIndex]
}
