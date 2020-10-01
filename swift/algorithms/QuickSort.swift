import Foundation

func sortArray(_ nums: [Int]) -> [Int] {
    guard nums.count > 1 else { return nums }
    let pivot = nums[nums.count/2]
    print("pivot: \(pivot)")
    let less = nums.filter { $0 < pivot }
    print("less: \(less)")
    let equal = nums.filter { $0 == pivot }
    print("equal: \(equal)")
    let greater = nums.filter { $0 > pivot }
    print("greater: \(greater)")
    return sortArray(less) + equal + sortArray(greater)
}

sortArray([5,2,3,1])
sortArray([5,1,1,2,0,0])
