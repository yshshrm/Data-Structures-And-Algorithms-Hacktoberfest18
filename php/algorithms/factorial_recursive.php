<?php

function factorial($n) {
	if($n <= 1) return 1;
	return (int)$n * factorial((int)$n - 1);
}

// Test
$number = 10;
print_r($number . "! = " . factorial($number));