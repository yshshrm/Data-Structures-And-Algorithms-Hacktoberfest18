<?php

class BinarySearch
{

	static public function search($value, $array)
	{
		$top = sizeof($array) - 1;
		$bottom = 0;

		while($top >= $bottom) {

			$middle = floor( ($top + $bottom) / 2);
			if($array[$middle] < $value) $bottom = $middle + 1;
			elseif ( $array[$middle] > $value) $top = $middle - 1;
			else return true;

		}

		return false;
	}

}