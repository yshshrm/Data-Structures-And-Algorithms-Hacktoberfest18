package lambdaCollectionFunctions



// Map => Returns new list/map containing all the values but after some operation on them
// Filter=>By applying filter , a new list is returned which satisfies the passed lambda
fun main(args: Array<String>) {

    // ----------------------------------------------- On Arrays
    var arr = ArrayList<Int>()
    arr.add(3);arr.add(30);arr.add(35);arr.add(2);arr.add(4);arr.add(9)
    // ...........[applying filter]{[element to be checked]->[predicate]}
    var filteredNum = arr.filter { s -> listFilter(s) } // 'it' can also be applied here
    println("fitered numbers of array $filteredNum")
    println("Squared the numbers using map operation ${arr.map { s -> s * s }}") // it*it
    println("Both together ${arr.filter { listFilter(it) }.map { it * it }}")


    // ----------------------------------------------- On Maps
    var myList = listOf<String>("Jennifer", "Aniston", "Winget", "Lawrence", "Lopez", "garner", "conelly") // Immutable
    var map = HashMap<Int, String>()
    for (i in 0..myList.size - 1)
        map.put(i, myList.get(i))

    println(map.filter { mapFilter(it) })

}

fun mapFilter(m: Map.Entry<Int, String>): Boolean = m.key > 2

fun listFilter(s: Int): Boolean = (s < 5 || s > 31)
