fun quicksort(array: Array<Int>): Array<Int>{ 
    //We take the first element as pivot and divide the array
    val pivot = array[0]
    val newArray = array.copyOfRange(1, array.size)
    var qs1 = arrayOf<Int>()
    var qs2 = arrayOf<Int>()
    for (elem in newArray){
        if (elem < pivot){
            qs1+=elem
        }
        else{
            qs2+=elem
        }
    }
    //Only use quicksort recursively if the list has more than one element
    if (qs1.size > 1){
        qs1 = quicksort(qs1)
    }
    if (qs2.size > 1){
        qs2 = quicksort(qs2)
    }
    
    return qs1 + pivot + qs2
}

fun main(args: Array<String>) {
    //Test array, should print 0 1 1 2 2 4 5 6 6 8 8 8 
    var array = arrayOf<Int>(4,8,2,6,1,0,5,8,2,6,8,1)
    for (elem in quicksort(array)){
        print("${elem} ")
    }
}