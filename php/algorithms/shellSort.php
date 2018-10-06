<?php
function shellSort($array)
{
    $x = round(count($array)/2);
    while($x > 0)
    {
        for($i = $x; $i < count($array);$i++){
            $temp = $array[$i];
            $j = $i;
            while($j >= $x && $array[$j-$x] > $temp)
            {
                $array[$j] = $array[$j - $x];
                $j -= $x;
            }
            $array[$j] = $temp;
        }
        $x = round($x/2.2);
    }
    return $array;
}

$arrayTest = array(2, 1, 0, 10, -6, 12, 22);
echo "Unsorted Array\n";
echo implode(', ',$arrayTest );
echo "\nSorted Array\n";
echo implode(', ',shellSort($arrayTest)). PHP_EOL;