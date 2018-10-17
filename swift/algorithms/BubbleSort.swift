import Foundation

//Implementation of BubbleSort
//****************************

func bubbleSort( _ a:inout [Int]){
    let size = a.count
    for i in 0..<size{
      let k = size-i-1
        for j in 0..<k{
            if(a[j+1]<a[j]){
                a.swapAt(j, j+1)
                }
        }
    }
    
}


//Testing the code
//****************

var a = [1,2,3,6,3,4,1,2]
bubbleSort(&a)
print(a)

var b = [1]
bubbleSort(&b)
print(b)

var c = [0,0,0,5,0,9]
bubbleSort(&c)
print(c)
