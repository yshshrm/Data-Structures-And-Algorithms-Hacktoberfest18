fn binary_search(arr: &mut [i32], n: i32) -> i32 {
    let mut start = 0;
    let mut end = arr.len();
    arr.sort();
    let mut mid;
    let mut res: i32 = -1;
    while start <= end {
        mid = (start + end) / 2;
        if arr[mid] == n {
            res = mid as i32;
            break
        } else if arr[mid] < n {
            start = mid + 1;
        } else { 
            end = mid - 1;
        }
    }
    return res
}

fn main () {
  let mut A = [1,2,3,4,5,6,7,8,9, 10];
  let n = binary_search(&mut A, 5);
  println!("{}", n);
}
