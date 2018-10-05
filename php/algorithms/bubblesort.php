<?php

$example = array(12,2,5,6,9, -1, 23, 3);
$array_size = count($example); 
$count = 0; //How many times it sorts
$i = 1; // Used itterator

//Print our numbers
echo "<br>Our numbers: <br>";
echo "----------<br>";

for ( $array = 0; $array < $array_size; $array++ )  //Print all the values within the array
   echo " <br>". $example[$array]; 
        
// Order the arrays different values. From highest to lowest
for ( $array = 0; $array < $array_size; $array++ ) 
{
   for ($arrayValue = 0; $arrayValue < $array_size -1; $arrayValue++ )
   {
      if ($example[$arrayValue +1] > $example[$arrayValue])
      {
         $temp = $example[$arrayValue]; 
         $example[$arrayValue] = $example[$arrayValue+1]; //The Swapping Part
         $example[$arrayValue+1] = $temp;
		 $count++;
		 echo "SORTED". $i. "<br>";  //Prints amount of /sortings in the array
		 $i++;
      }
   }
}

// Print the order
echo "<br>Bubblin' ordering: <br>";
echo "----------<br>";
for( $array = 0; $array < $array_size; $array++ )  //  Let's print our values in order 
    echo  "<br>". $example[$array];

//Total times the sorting occoured
echo  "<br><br><br> The code sorted the numbers: ". $count. " times.";
