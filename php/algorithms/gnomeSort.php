<?php
function gnomeSort($array){
    $i = 1;
    $j = 2;
    while($i < count($array)){
        if ($array[$i-1] <= $array[$i]){
            $i = $j;
            $j++;
        }else{
            list($array[$i],$array[$i-1]) = array($array[$i-1],$array[$i]);
            $i--;
            if($i == 0){
                $i = $j;
                $j++;
            }
        }
    }
    return $array;
}
$arrayTest = array(2, 1, 0, 10, -6, 12, 22);
echo "Unsorted Array\n";
echo implode(', ',$arrayTest );
echo "\nSorted Array\n";
echo implode(', ',gnomeSort($arrayTest)). PHP_EOL;
