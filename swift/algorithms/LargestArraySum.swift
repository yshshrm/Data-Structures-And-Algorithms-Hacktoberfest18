func largestArraySum(arrayOne: [Int], arrayTwo: [Int]) {
    let sumOne = arrayOne.reduce(0, {$0 + $1})
    let sumTwo = arrayTwo.reduce(0, {$0 + $1})
    
    if sumOne > sumTwo {
        print("Array One has the largest sum: \(sumOne)")
    } else if sumTwo > sumOne {
        print("Array Two has the largest sum: \(sumTwo)")
    } else if sumOne == sumTwo {
        print("Both array sums are equal")
    }
}
