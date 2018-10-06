package basics


import java.math.BigInteger

//We can use extension functins to add functionality to existing predefined classes our custom classes
fun main(args: Array<String>) {

    var s1 = "cb"
    var s2 = "coder"
    var s3 = "av"
    println(s3.add3(s1, s2))

    val x = 5
    val y = 10
    val max = x max y//Just like operators

    val c = fib(10000, BigInteger("0"), BigInteger("1"))
    println(c)
}

//This function can only be extension function not INFIX since it have more than one params
fun String.add3(s1: String, s2: String): String = this + s1 + s2

//It can be declared as INFIX since it have only 1 param
//It increases readability of code
infix fun Int.max(a: Int): Int = if (a > this) a else this

//Tailrec functions prevents stackOverflow error
tailrec fun fib(n: Int, a: BigInteger, b: BigInteger): BigInteger = if (n == 0) b else fib(n - 1, a + b, a)