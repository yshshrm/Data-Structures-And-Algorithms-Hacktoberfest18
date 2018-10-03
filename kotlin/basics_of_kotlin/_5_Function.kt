package basics



fun main(args: Array<String>) {
    println(high()("av"))
    val a = 2
    val b = 3
    println(add2(a, b))
    //After naming order doesn't matters
    //Mixing is not allowed i.e either all params should be named or ordering should be maintained
    struct(breadth = 12, length = 3, height = 1)

    var ans = global { println("called lambda function from $it") }
    println(ans(2, 3))
}

fun add1(a: Int, b: Int): Int {
    return a + b
}

fun add2(a: Int, b: Int) = a + b

fun max(a: Int, b: Int) = if (a > b) a else b

//Concept of named params
fun struct(length: Int, breadth: Int, height: Int) {
    println(length)
    println(breadth)
    println(height)
}

fun global(l: (String) -> Unit): (Int, Int) -> (Int) {
    l("global fun scope")
    // Inner function can also be made in kotlin
    fun inner(il: (String) -> Unit) = il("inner fun scope")
    inner(l)
    fun add(a: Int, b: Int): Int = a + b //.....?
    return { a, b -> a + b }
}

// Inner functions
fun high(): (String) -> String {
    fun inner(i: String): String {
        return "hello $i"
    }
    return ::inner
}