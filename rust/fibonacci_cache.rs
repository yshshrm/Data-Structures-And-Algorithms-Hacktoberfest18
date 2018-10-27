fn fibonacci_cache(n: usize, cache: &mut [u128]) -> u128 {
	let val: u128 = cache[n];
	if val == 0 {
		cache[n] = fibonacci_cache(n-1, cache) + fibonacci_cache(n-2, cache);
	}
	return cache[n];
}


fn main() {
	let mut fibs: [u128; 1000] = [0;1000];
	fibs[0] = 1;
	fibs[1] = 1;

	// Max value that can be computed without overflow
	println!("{:?}", u128::max_value()));
    println!("Fib(185) = {}", fibonacci_cache(185, &mut fibs));

}
