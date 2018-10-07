fn selection_sort<T: Ord>(list: &mut [T]) {
    for index in 0..list.len() {
        let mut minimum_index = index;
        for item in index + 1..list.len() {
            if list[minimum_index] > list[item] {
                minimum_index = item;
            }
        }
        list.swap(minimum_index, index);
    }
}

fn main() {
    let mut list = vec![41, 21, 73, -11, 0, -56, 5];
    println!("Base list: {:?}", list);
    selection_sort(&mut list);
    println!("\nSorted list: {:?}", list);
}