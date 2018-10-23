fn partition<T: Ord + Copy>(arr: &mut [T], l: usize, r: usize) -> usize {
    let pivot = arr[r];
    let mut i = l;

    for j in l..r {
        if arr[j] < pivot {
            arr.swap(i, j);
            i += 1;
        }
    }

    if arr[r] < arr[i] {
        arr.swap(i, r);
    }

    i
}

fn quick_sort<T: Ord + Copy>(arr: &mut [T], l: isize, r: isize) {
    if l < r {
        let p = partition(arr, l as usize, r as usize) as isize;

        quick_sort(arr, l, p - 1);
        quick_sort(arr, p + 1, r);
    }
}

fn main() {
    let mut arr = vec![0, 8, 4, 7, 1, 9, 10, 5, 2, 11, 3];
    let len = arr.len() as isize;
    quick_sort(&mut arr, 0, len - 1);

    for i in arr {
        print!("{} ", i);
    }

    println!("");
}
