
fn fibonacci(n: u64) -> u64 {
	if n < 2 {
		return 1;
	}
	else {
		return fibonacci(n-1) + fibonacci(n-2);
	}
}


fn main() {
    println!("Fib(40) = {}", fibonacci(41));
}
