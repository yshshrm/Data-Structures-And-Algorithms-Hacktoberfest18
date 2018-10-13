// Return the factorial of an integer

function factorialize(num) {
	var factorial = 1;

	for (var i = 1; i <= num; i++) {
		factorial *= i;
	}

  return factorial;
}