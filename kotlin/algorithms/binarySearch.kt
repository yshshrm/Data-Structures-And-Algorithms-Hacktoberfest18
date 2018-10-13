fun main(args: Array<String>) {
    val arr = intArrayOf(10, 20, 25, 30, 35 ,40, 50)
        val find = 30
        val ans = binarySearch(arr, find)
    println("answer : "+ans)
}

fun binarySearch(arr: IntArray, find: Int): Int {
        var l = 0
        var r = arr.size - 1
        while (l <= r) {
            val mid = l + r shr 1
            when {
                arr[mid] == find -> return mid
                arr[mid] < find -> l = mid + 1
                else -> r = mid - 1
            }
        }
        return -1
}
