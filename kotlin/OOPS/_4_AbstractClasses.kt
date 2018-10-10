package OOPS


fun main(args: Array<String>) {
    var d = der()
}

//If any one property/method is abstract then class must be abstract
//Object of this class can not be created but derived class can call its constructor
abstract class base(var baseParam: String) {
    init {
        println("init of base")
    }

    abstract var absVar: String//It must be defined in derived class
    abstract fun absFun()//It must be defined in derived class
    open fun openFun() {}//It can be redefined
}

class der : base("5") {
    init {
        println("init of derived")
        println(baseParam)
    }

    override var absVar: String = "overrided property"
    override fun absFun() = println("Overrider function")
}