<?php
function combSort($array)
{
    $gap = count($array);
    $swap = true;
    while ($gap > 1 || $swap){
        if($gap > 1) $gap /= 1.25;
        $swap = false;
        $i = 0;
        while($i+$gap < count($array)){
            if($array[$i] > $array[$i+$gap]){
                list($array[$i], $array[$i+$gap]) = array($array[$i+$gap],$array[$i]);
                $swap = true;
            }
            $i++;
        }
    }
    return $array;
}
$arrayTest = array(2, 1, 0, 10, -6, 12, 22);
echo "Original Array :\n";
echo implode(', ',$arrayTest );
echo "\nSorted Array\n:";
echo implode(', ',combSort($arrayTest)). PHP_EOL;
