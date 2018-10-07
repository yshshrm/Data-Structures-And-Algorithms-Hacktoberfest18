<?php

function array_sort($arr) {
  for($i = 0;$i<count($arr);$i++){
    for($j = 0;$j<count($arr) - 1;$j++){
      if($arr[$j]>$arr[$j+1]){
        $temp = $arr[$j];
        $arr[$j]= $arr[$j+1];
        $arr[$j+1]= $temp;
      }
    }
  }
  
  return $arr;
}


var_dump(array_sort([1, 10, 3, 13, 8]));
// [1, 3, 8, 10, 13]