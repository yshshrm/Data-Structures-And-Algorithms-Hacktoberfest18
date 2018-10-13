
<?php 
function binarySearch($arr, $l, $r, $x) 
{ 
if ($r >= $l) 
{ 
        $mid = $l + ($r - $l) / 2; 
  
        // If the element is present  
        // at the middle itself 
        if ($arr[$mid] == $x)  
            return floor($mid); 
  
        // If element is smaller than  
        // mid, then it can only be  
        // present in left subarray 
        if ($arr[$mid] > $x)  
            return binarySearch($arr, $l,  
                                $mid - 1, $x); 
  
        // Else the element can only  
        // be present in right subarray 
        return binarySearch($arr, $mid + 1,  
                            $r, $x); 
} 
  
// We reach here when element  
// is not present in array 
return -1; 
} 
  
// Driver Code 
$arr = array(2, 3, 4, 10, 40); 
$n = count($arr); 
$x = 10; 
$result = binarySearch($arr, 0, $n - 1, $x); 
if(($result == -1)) 
echo "Element is not present in array"; 
else
echo "Element is present at index ", 
                            $result; 
?> 

