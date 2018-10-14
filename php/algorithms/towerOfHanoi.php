 <!-- Problem

 Tower of Hanoi is a mathematical puzzle where we have three rods and n disks.
 The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:
 1) Only one disk can be moved at a time.
 2) Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
 3) No disk may be placed on top of a smaller disk. -->

<?php 
//PHP code to solve Tower of Hanoi problem. 
  
// Recursive Function to solve Tower of Hanoi 
function towerOfHanoi($n, $from_rod, $to_rod, $aux_rod) { 
      
    if ($n === 1) { 
    echo ("Move disk 1 from rod $from_rod to rod $to_rod \n"); 
    return; 
    }  
      
    towerOfHanoi($n-1, $from_rod, $aux_rod, $to_rod); 
    echo ("Move disk $n from rod $from_rod to rod $to_rod \n"); 
    towerOfHanoi($n-1, $aux_rod, $to_rod, $from_rod); 
  
} 
  
// Driver code 
  
// number of disks 
$n = 4; 
  
// A, B and C are names of rods 
towerOfHanoi($n, 'A', 'C', 'B'); 
  
?> 

<!-- Author - https://github.com/gupta-ji6 -->