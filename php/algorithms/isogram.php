<?php

class isogram {
  function isIsogram( $word ) {
    $word = strtolower($word); // convert to lowercase
    $len = strlen($word); // get legth of word
    $arr_word = str_split($word); // convert to array
    $res = '';
    sort($arr_word); // sort array
    for($i = 0; $i < $len-1; $i++) {
      if($arr_word[$i] == $arr_word[$i+1]) {
        $res = $word.' is not an isogram, '. $arr_word[$i] .' repeats';
        return $res;
      }
    }
    return $word.' is an isogram';
  }
}

// Test Isogram
$getIsogram = new isogram();
echo $getIsogram->isIsogram( 'chcracter' );
echo $getIsogram->isIsogram( 'isogram' );
echo $getIsogram->isIsogram( 'isograms' );