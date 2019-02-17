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

fn merge_sort<T: Ord + Copy>(arr: &mut [T], l: u32, r: u32) {
    if l < r {
        let m: u32 = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

fn main() {
    let mut array = vec![0, 8, 4, 7, 1, 9, 10, 5, 2, 11, 3];
    let arr_size = array.len() as u32;
    println!("{:?}", array);
    merge_sort(&mut array, 0, arr_size - 1);
    println!("{:?}", array);

}
