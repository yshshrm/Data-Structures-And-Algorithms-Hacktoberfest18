fn insertion_sort<T: Ord + Copy>(arr: &mut [T]) {
    for i in 1..arr.len() {
        let key = arr[i];
        let mut j = i - 1;

        while arr[j] > key {
            arr.swap(j, j + 1);
            j -= 1;
        }

        arr[j + 1] = key;
    }
}

fn main() {
    let mut array = vec![0, 8, 4, 7, 1, 9, 10, 5, 2, 11, 3];
    println!("{:?}", array);
    insertion_sort(&mut array);
    println!("{:?}", array);

}
