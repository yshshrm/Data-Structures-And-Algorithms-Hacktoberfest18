fun main(args: Array<String>) =
    println(linearSearch(intArrayOf(1, 2, 3, 4 ,5), 2))


fun linearSearch(arr: IntArray, item: Int): Int =
        (0 until arr.size).firstOrNull { arr[it] == item } ?: -1
