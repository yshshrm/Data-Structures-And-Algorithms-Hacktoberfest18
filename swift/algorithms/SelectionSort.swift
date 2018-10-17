

import Foundation


func selectionSort(_ a:inout [Int]){
    
    for i in 0..<(a.count-1){
        let k = i+1
        var temp = a[i]
        var tempi = i
        for j in k..<a.count{
            if a[j]<temp{
                temp = a[j]
                tempi = j
            }
        }
        a.swapAt(i,tempi)
    }
}


//Testing code

var a = [3,9,2,1,0,9,8]
selectionSort(&a)
print(a)
