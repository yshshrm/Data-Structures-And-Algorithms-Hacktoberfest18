/**
 * Program 

<?php
function pg_quick_sort($my_array)
 {
	$loe = $gt = array();
	if(count($my_array) < 2)
	{
		return $my_array;
	}
	$pivot_key = key($my_array);
	$pivot = array_shift($my_array);
	foreach($my_array as $val)
	{
		if($val <= $pivot)
		{
			$loe[] = $val;
		}elseif ($val > $pivot)
		{
			$gt[] = $val;
		}
	}
	return array_merge(pg_quick_sort($loe),array($pivot_key=>$pivot),pg_quick_sort($gt));
}
 
$my_array = array(3, 0, 2, 5, -1, 4, 1);
echo 'Original Array : '.implode(',',$my_array).'\n';
$my_array = pg_quick_sort($my_array);
echo 'Sorted Array : '.implode(',',$my_array);
?>

================

##Sample Output:

Original Array : 3,0,2,5,-1,4,1                             
Sorted Array : -1,0,1,2,3,4,5 
