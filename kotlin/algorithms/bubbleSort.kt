 fun sort(arr: Array<Long>): Array<Long> {
        var items = false
        do {
             (0..arr.size - 2)
                    .filter { arr[it] > arr[it + 1] }
                    .forEach {
                        swap(arr.toMutableList(), it, it + 1)
                        items = true
                    }
        } while (items)
        return arr
    }
