fun main(args: Array<String>) =
    println(binarySearch(intArrayOf(1, 2, 3, 4 ,5), 2))

fun binarySearch(a: IntArray, b: Int): Int {
    var lower = 0
    var higher = a.size
    var mid: Int
    while (lower <= higher) {
        mid = lower + (higher - lower) / 2
        when {
            a[mid] == b -> return mid
            a[mid] < b -> lower = mid + 1
            a[mid] > b -> higher = mid - 1
        }
    }
    return -1
}
