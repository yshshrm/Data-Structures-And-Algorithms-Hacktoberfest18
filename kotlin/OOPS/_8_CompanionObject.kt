package OOPS


fun main(args: Array<String>) {
    println(CompClass.staticField)
    CompClass.staticFun()
}

class CompClass {
    // After compilation, fields inside companion object actually becomes static fields of class
    companion object { // These can be accessed using class name only , not by objects

        var staticField: Int = 50

        @JvmStatic //Using this, the function can now be accessed even from JAVA class
        fun staticFun() = println("Actual static function")
    }
}