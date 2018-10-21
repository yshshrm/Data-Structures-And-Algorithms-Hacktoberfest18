fn selection_sort<T: Ord>(arr: &mut [T]) {
    for i in 0..arr.len() {
        let mut smallest = i;
        for j in (i+1)..arr.len() {
            if arr[j] < arr[smallest] {
                smallest = j;
            }
        }
        arr.swap(i, smallest);
    }
}

fn main() {
    let mut array = vec![9, 2, 7, 4, 1, 8, 14, 9, 0, 13, 5];
    println!("{:?}", array);
    selection_sort(&mut array);
    println!("{:?}", array);
}
