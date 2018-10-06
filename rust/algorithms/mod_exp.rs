// Returns m^e % n
fn mod_exp(mut m: u64, mut e: u64, n: u64) -> u64 {
    let mut result = 1 % m;
    while e > 0 {
        if e % 2 == 1 {
            result = (result * m) % n;
        }
        m = (m * m) % n;
        e /= 2;
    }
    return result
}

fn main() {
    let example = mod_exp(2790, 413, 3233);
    println!("2790 ^ 413 mod 3222 = {}", example);
}