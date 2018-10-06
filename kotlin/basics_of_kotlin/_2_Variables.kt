package basics

/*
 * type inference is used in kotlin
 * var can be reassigned but val can not be
 * There are no primitive data types in Kotlin
 * All the data types are objects, so there is no default values for them
 * Boolean(1) Byte(8) Char(16) Short(16) Int(32) Long(64,L) Float(32,f,F) Double(64,d,D)
 * string interpolation is used in kotlin (" ${} ")
 */

fun main(args: Array<String>) {
    val myString = "avcbcoder"
    println(myString)
    //myString="cannot be reassigned"

    var s = "hello"
    s = "name is ${s}"//interpolation
    println(s)

    var a = 10
    var b = 20
    println("Answer is ${a + b} and a is $a")

    var marksfloat: Float
    var marksdouble: Double
    marksfloat = 99.6f
    marksdouble = 99.6

    // Casting

    val int:Int="123".toInt()
    println(int)
}
