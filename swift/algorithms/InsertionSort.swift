

import Foundation


func InsertionSort(_ a:inout [Int]){
    
    for i in 1..<a.count{
        
        let temp = a[i]
        var k = i-1
        while k>=0 && a[k]>temp{
            a[k+1]=a[k]
            k = k-1
            
            }
        
        a[k+1] = temp
        }
    
    }


//Testing code

var a = [100,58,0,9,22,3,21,23,4,1,3]
InsertionSort(&a)
print(a)
