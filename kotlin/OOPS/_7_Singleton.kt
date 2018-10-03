package OOPS



// In JAVA we create singleton using static keyword, Since there is no such keyword in kotlin
// So alternative to this : Declare object (this creates a singleton object when code runs)

fun main(args: Array<String>) {
    StaticGroup.staticFun()
    DerObject.myFun()
}

// It will be internally converted into singleton object ,
// whose properties can be called using name.<property_name>
// All properties of object acts as static
object StaticGroup {
    private var staticVar: String = "" // protected modifier is not applicable in 'object'
    fun staticFun() = println("static function callled") // Behaves as static but not static actually
    internal var b: Int = 5
}

open class BaseClass {
    open fun myFun() = println("base function")
}

object DerObject : BaseClass() {
    var a = 5
    override fun myFun() {
        println("Overrided method")
        super.myFun() // Acts as static now
    }
}