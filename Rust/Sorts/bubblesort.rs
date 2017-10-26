fn bubblesort(array: &mut [i32]) {
    let mut n = array.len();
    while n > 0 {
        let mut newn = 0;
        for i in 0..n-1 {
            if array[i] > array[i+1] {
                let temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                newn = i+1;
            }
        }
        n = newn;
    }
}

fn main() {
    let mut values = [5, 8, 4, 1, 7, 2, 3, 6];
    println!("values: {:?}", values);
    bubblesort(&mut values);
    println!("sorted: {:?}", values);
}
