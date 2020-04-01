
// Function Checks whether array A is a permutation.
// A permutation is a sequence containing each element from 1 to N once, and only once.


func permCheckXor(data: [Int]) -> Int{
    
    let N = data.count
    
    var xorToN = xor(to: N)
    
    for val in data {
        
        if val > N {
            return 0
        }
        
        xorToN ^= val
    }
    
    return xorToN == 0 ? 1 : 0
}


// Function Computes the XOR of integers from 0 to number in O(1) time.
func xor(to number: Int ) -> Int {
    
    switch number % 4 {
        
    case 0:
        return number
    case 1:
        return 1
    case 2:
        return number + 1
    default:
        return 0
    }
    
}
