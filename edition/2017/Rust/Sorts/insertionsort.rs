fn insertionsort(array: &mut [i32]) {
    let mut i = 1;
    while i < array.len() {
        let mut j = i;
        while j > 0 && array[j-1] > array[j] {
            array.swap(j, j-1);
            j -= 1;
        }
        i += 1;
    }
}

fn main() {
    let mut values = [2, 36, 457, 3, 276, 865835, 3, 727, 2, 1];
    println!("values: {:?}", values);
    insertionsort(&mut values);
    println!("sorted: {:?}", values);
}
