fn selection_sort<T: Ord>(arr: &mut Vec<T>) {
    _selection_sort(arr, 0);
}

fn _selection_sort<T: Ord>(arr: &mut Vec<T>, offset: usize) {
    let mut smallest_index = offset.clone();
    for i in (offset+1)..arr.len() {
        if arr[i] < arr[smallest_index] {
            smallest_index = i;
        }
    }
    if smallest_index != offset {
        arr.swap(smallest_index, offset.clone())
    }
    if offset < arr.len() {
        _selection_sort(arr, offset + 1)
    }
}

fn main() {
    let mut array = vec![0, 8, 4, 7, 1, 9, 10, 5, 2, 11, 3];
    println!("{:?}", array);
    selection_sort(&mut array);
    println!("{:?}", array);

}