<?php
function cocktailSort($array)
{
    if (is_string($array))
        $array = str_split(preg_replace('/\s+/','',$array));

    do{
        $swapped = false;
        for($i=0;$i<count($array);$i++){
            if(isset($array[$i+1])){
                if($array[$i] > $array[$i+1]){
                    list($array[$i], $array[$i+1]) = array($array[$i+1], $array[$i]);
                    $swapped = true;
                }
            }
        }

        if ($swapped == false) break;

        $swapped = false;
        for($i=count($array)-1;$i>=0;$i--){
            if(isset($array[$i-1])){
                if($array[$i] < $array[$i-1]) {
                    list($array[$i],$array[$i-1]) = array($array[$i-1],$array[$i]);
                    $swapped = true;
                }
            }
        }
    }while($swapped);

    return $array;
}
$arrayTest = array(2, 1, 0, 10, -6, 12, 22);
echo "Unsorted Array\n";
echo implode(', ',$arrayTest );
echo "\nSorted Array\n";
echo implode(', ',cocktailSort($arrayTest)). PHP_EOL;