use std::cmp;

const SUB_ARRAY_SIZE: usize = 32;

fn insertion_sort<T: Ord + Copy>(arr: &mut [T], l: usize, r: usize) {
    let mut i = l + 1;
    while i <= r {
        let key = arr[i];
        let mut j: i32 = i as i32 - 1;

        while j >= l as i32 && arr[j as usize] > key {
            arr[(j + 1) as usize] = arr[j as usize];
            j -= 1;
        }

        arr[(j + 1) as usize] = key;

        i += 1;
    }
}

fn merge<T: Ord + Copy>(arr: &mut [T], l: u32, m: u32, r: u32) {
    let n1 = m - l + 1;
    let n2 = r - m;

    let mut l_temp: Vec<T> = Vec::new();
    let mut r_temp: Vec<T> = Vec::new();

    for i in 0..n1 {
        l_temp.push( arr[(l + i) as usize]);
    }
    for i in 0..n2 {
        r_temp.push(arr[(m + 1 + i) as usize]);
    }

    let mut i: u32 = 0;
    let mut j: u32 = 0;
    let mut k: u32 = l;

    while i < n1 && j < n2 {
        if l_temp[i as usize] <= r_temp[j as usize] {
            arr[k as usize] = l_temp[i as usize];
            i += 1;
        }
        else {
            arr[k as usize] = r_temp[j as usize];
            j += 1;
        }
        k += 1;
    }

    while i < n1 {
        arr[k as usize] = l_temp[i as usize];
        i += 1;
        k += 1;
    }

    while j < n2 {
        arr[k as usize] = r_temp[j as usize];
        j += 1;
        k += 1;
    }
}

fn tim_sort<T: Ord + Copy>(arr: &mut [T]) {
    for i in (0..arr.len()).step_by(SUB_ARRAY_SIZE) {
        let upper_limit: usize = cmp::min(i + (SUB_ARRAY_SIZE - 1), arr.len() - 1);
        insertion_sort(arr, i as usize, upper_limit);
    }

    let mut size = SUB_ARRAY_SIZE;
    while size < arr.len() {
        let mut l = 0;
        while l < arr.len() {
            let m = l + size - 1;
            let r = cmp::min(l + 2 * size - 1, arr.len() - 1);

            merge(arr, l as u32, m as u32, r as u32);

            l += 2 * size;
        }
        size *= 2;
    }
}

fn main() {
    let mut array = vec![1, 0, 8, 4, 7, 1, 9, 10, 5, 2, 11, 3];
    println!("{:?}", array);
    tim_sort(&mut array);
    println!("{:?}", array);
    
    let mut big_array = vec![-85, -42, -93, -38, 39, 34, -80, -85, 61, 51, -77, 92, 98, -23, 94, -90, 80, 15, 34, -69, -38, 16, 78, -72, -68, -54, 100, -81, 0, 36, -32, -53, -8, 98, -1, -62, 88, -52, -78, 38, -47, -81, 52, 35, 83, -46, 62, -83, 99, -37, -66, -12, 55, 46, -73, 7, 45, -40, 99, 41, 91, 88, -49, 9, 37, -24, -32, -7, -65, -20, -66, 39, -49, 65, -21, 92, 83, -48, 73, -99, -49, -79, 61, -29, 23, -18, 63, 20, 91, -12, 40, -100, 15, 43, 54, -28, -67, -92, -10, 97, -59, 78, -95, 25, -28, 87, 24, 89, -35, 20, -96, -18, -50, -87, 47, 77, 13, -52, -82, -85, -66, -49, -57, -44, -31, 67, -26, 11];
    println!("{:?}", big_array);
    tim_sort(&mut big_array);
    println!("{:?}", big_array);
}

