fn shell_sort<T: Ord>(arr: &mut [T]) {
    let mut gap = arr.len() / 2;
    while gap > 0 {
        for i in gap..arr.len() {
            let mut j = i;
            while j >= gap && arr[j - gap] > arr[i] {
                arr.swap(j, j - gap);
                j -= gap;
            }
        }
        gap = gap / 2;
    }
}

fn main() {
    let mut array = vec![0, 8, 4, 7, 1, 9, 10, 5, 2, 11, 3];
    println!("{:?}", array);
    shell_sort(&mut array);
    println!("{:?}", array);

}