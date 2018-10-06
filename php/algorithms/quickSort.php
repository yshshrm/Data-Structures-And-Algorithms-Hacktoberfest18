<?php

function quickSort($array)
{
    $length = count($array);

    if($length <= 1){
        return $array;
    }
    else{
        $pivot = $array[0];
        $left = $right = array();

        for($i = 1; $i < count($array); $i++)
        {
            if($array[$i] < $pivot){
                $left[] = $array[$i];
            }
            else{
                $right[] = $array[$i];
            }
        }
        return array_merge(quickSort($left), array($pivot), quickSort($right));
    }
}
$arrayTest = array(2, 1, 0, 10, -6, 12, 22);
echo "Unsorted Array\n";
echo implode(', ',$arrayTest );
echo "\nSorted Array\n";
echo implode(', ',quickSort($arrayTest)). PHP_EOL;
