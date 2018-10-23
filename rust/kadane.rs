fn kadane(arr: &[isize]) -> (isize, usize, usize) {
    // Maximum so far, maximum ending here
    let (mut msf, mut meh) = (-0x3f3f3f3f, 0);
    let (mut start, mut end, mut s) = (0, 0, 0);

    for (i, x) in arr.iter().enumerate() {
        meh = meh + x;

        if msf < meh {
            msf = meh;
            start = s;
            end = i;
        }

        if meh < 0 {
            meh = 0;
            s = i + 1;
        }
    }

    (msf, start, end)
}

fn main() {
    let arr = vec![-2, -3, 4, -1, -2, 1, 5, -3];
    let ans = kadane(&arr);

    println!("Largest sum contiguous subarray: {}", ans.0);
    println!("Starts at: {}", ans.1);
    println!("Ends at: {}", ans.2);
}
