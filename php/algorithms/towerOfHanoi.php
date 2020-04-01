<?php

function TOH($stack, $begin, $aux, $end){
    if($stack == 0) return;
    echo "stack = ".$stack."/".$begin."/".$aux."/".$end."\r\n";
    
    TOH($stack - 1, $begin, $end, $aux);
    echo $begin." ".$end."\r\n";
    TOH($stack - 1, $aux, $begin, $end);
}

$stdin = fopen("php://stdin","r");
$towerHigh = fgets($stdin);
TOH((int)$towerHigh,"a","b","c");

?>