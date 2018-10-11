// Quicksort is a sorting algorithm that sorts a "pivot" element, 
// then recurses on the unsorted two halves on either side of the pivot.
// Reference: https://www.geeksforgeeks.org/quick-sort/

fn partition(arr: &mut [i32], low: i32, high: i32) -> i32 {
	let pivot: i32 = arr[high as usize]; // use last element as pivot
	let mut smaller: i32 = low - 1; // keeps track of how many elements are smaller than pivot element

	for i in low..high {
		if arr[i as usize] <= pivot {
			smaller += 1; // found another element less than pivot
			arr.swap(i as usize, smaller as usize); // place element i on left side of pivot
		}
	}
	arr.swap((smaller + 1) as usize, high as usize); // put pivot into place
	return smaller + 1
}

fn quicksort(arr: &mut [i32], low: i32, high: i32) {
	if low < high {
		let pivot: i32 = partition(arr, low, high); // sort the pivot element, split array on pivot
		quicksort(arr, low, pivot - 1); // sort left half
		quicksort(arr, pivot + 1, high); // sort right half
	}
}

fn main() {
	let mut arr: [i32; 6] = [6, 5, 4, 3, 2, 1];
	let end: usize = arr.len() - 1; // end of the array

	println!("Original array: {:?}", arr);
	quicksort(&mut arr, 0, end as i32); // sort array in place
	println!("Sorted array: {:?}", arr);
}