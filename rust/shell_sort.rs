fn shell_sort<T: Ord>(arr: &mut [T]) {
    for i in 0..arr.len() {
        for j in 0..arr.len() - 1 - i {
            if arr[j] > arr[j + 1] {
                arr.swap(j, j + 1);
            }
        }
    }
}

fn main() {
    let mut array = vec![0, 8, 4, 7, 1, 9, 10, 5, 2, 11, 3];
    println!("{:?}", array);
    shell_sort(&mut array);
    println!("{:?}", array);

}