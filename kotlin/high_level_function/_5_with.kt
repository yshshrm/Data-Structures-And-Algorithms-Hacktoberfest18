package high_level_function


fun main(args: Array<String>) {

    var c = MyClass()
    c.p1 = "--"
    c.p2 = "--"
    println(c)

    with(c) {
        this.p1 = "p1 using with" // We can use this,c(object_name) also
        p2 = "p2 using with" // usage of with
        var a = 3 + 2 // Normal codes can also be written here
        f() //Methods can also be called from here
    } // We can not call any method here since it doesn't return anything (blocks)
    println(c)

    c.apply {
        p1 = "p1 using apply" // We can use this,c(object_name) also
        p2 = "p2 using apply"
        var a = 3 + 2 // Normal codes can also be written here
        f() //Methods can also be called from here
    }.ready() //Methods can be called in end
}

class MyClass {
    var p1: String = ""
    var p2: String = ""

    override fun toString(): String {
        return p1 + " " + p2
    }

    fun f(): Unit {
        println("run called")
    }

    fun ready() {
        println("Initiallized all values")
    }
}