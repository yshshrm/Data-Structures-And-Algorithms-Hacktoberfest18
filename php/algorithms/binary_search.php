function binarySearch($A,$value,$starting,$ending)
    {
       if($ending<$starting)
       {
          return -1;
       }
       $mid=intVal(($starting+$ending)/2);

       if($value===$A[$mid])
          {
              return $mid;
          }
       else if($value<$A[$mid])
          {
             $ending=$mid-1;
          }
       else if($value>$A[$mid])
          {
             $starting=$mid+1;
          }

       return binarySearch($A,$value,$starting,$ending);
    }