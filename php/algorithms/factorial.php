<?php


if(!empty($argv['1'])) {
	$input = intval($argv['1']);
	$factorial = 1;
	for($x = $input; $x >= 1; $x--) {
		$factorial *= $x;
	}
	echo "Factorial for $input is " . $factorial;
} else {
	echo 'Please input a valid number following this command : php factorial.php <number>';
}

