package OOPS


// The purpose of data class is to just deal with data and not with the objects
fun main(args: Array<String>) {
    var d1 = dc("hello", 100)
    var d2 = dc("hello", 100)
    // In case of objects (if d1,d2 were not objects of data class then 'different' would have been printed)
    if (d1 == d2) println("Same data") else println("Different data")

    println(d1)

    var d3=d1.copy(v2 = 555) // It will copy v1 but not v2
    println(d3)
}

// Data classes compare data instead of objects
// It overrides toString() method itself
// New objects can easily be created using copy method
// Every class in kotlin is inherited from 'ANY' class which contains toStrin(),hashCode(),equals()
data class dc(var v1: String, var v2: Int)