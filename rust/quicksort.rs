fn partition<T: Ord + Copy>(arr: &mut [T], low: i32, high: i32) -> i32 {
    // note that this is not an optimal selection for the pivot point
    let pivot = arr[low as usize];

    let mut left = low + 1;
    let mut right = high;
    let mut done = false;

    while !done {
        while left <= right && arr[left as usize] <= pivot {
            left += 1;
        }
        while right >= left && arr[right as usize] >= pivot {
            right -= 1;
        }

        if right < left {
            done = true;
        }
        else {
            arr.swap(left as usize, right as usize);
        }
    }

    arr.swap(low as usize, right as usize);

    return right;
}

fn quicksort<T: Ord + Copy>(arr: &mut [T], low: i32, high: i32) {
    if low < high {
        let pivot = partition(arr, low, high);

        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }   
}

fn main() {
    let mut array = vec![1, 0, 8, 4, 7, 1, 9, 10, 5, 2, 11, 3];
    let arr_size: usize = array.len();
    println!("{:?}", array);
    quicksort(&mut array, 0, arr_size as i32 - 1);
    println!("{:?}", array);
}
