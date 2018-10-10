<?php



function insertionSort($array)
{
    $array_size = count($array);
    for ($i = 1; $i < $array_size; $i++) {
        $key = $array[$i];
        $j = $i-1;
        while ($j >= 0 && $array[$j] > $key) {
            $array[$j + 1] = $array[$j];
            $j = $j - 1;
        }
        $array[$j + 1] = $key;
    }
    return $array;
}


function printArray(array $array){
	for ($i = 0; $i < count($array); ++$i) {
        print $array[$i] . " ";
  }
	print "\n";
}


// Test
$array = array(46, 24, 33, 10, 2, 81, 50);
print "Unsorted array\n";
printArray($array);
print "Sorted array\n";
printArray(insertionSort($array));
?>
