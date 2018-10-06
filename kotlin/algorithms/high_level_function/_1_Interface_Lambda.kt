package high_level_function


// High level functions => which can either return a function or accept function as parameter
// Lambdas => functions without name
fun main(args: Array<String>) {

    addNum(2, 3)

    addNum(10, 20, object : PrintInterface {})

    addNum(a = 25, b = 33, print = object : PrintInterfaceMethod { // Instead of making new anonymous class like java, use object
        override fun printFun(sum: Int) {
            println("Using Custom function in params: $sum")
        }
    })

    var p = object : PrintInterfaceMethod {
        override fun printFun(sum: Int) {
            println("Using custom functions by assigning to variable $sum")
        }
    }

    addNum(10, 100, p)

    val a: Int = 105
    val lambda: (Int) -> Unit = { s: Int -> println("By passing lambda to function : $s") }
    addNum(32, 70, lambda)

    addNum(39, 74, { s: Int -> println("Using lambda function directly : $s") })

    addNum(39, 134) { s -> println("Another syntax : $s") }
}


fun addNum(a: Int, b: Int) {
    var c = a + b;
    println("Simple method : sum is $c")
}

fun addNum(a: Int, b: Int, print: PrintInterface) {
    var c = a + b;
    print.printFun(c)
}

fun addNum(a: Int, b: Int, print: PrintInterfaceMethod) {
    var c = a + b;
    print.printFun(c)
}

fun addNum(a: Int, b: Int, lambda: (Int) -> Unit) { // this statement means => lambda accepts an Int and returns an Int
    val c = a + b
    lambda(c)
}

interface PrintInterface {
    fun printFun(sum: Int) = println("Using Interface : sum is $sum")
}

interface PrintInterfaceMethod {
    fun printFun(sum: Int)
}