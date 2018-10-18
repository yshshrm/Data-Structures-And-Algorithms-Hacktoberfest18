package OOPS

fun main(args: Array<String>) {
    var c = myClass("first param")
    c = myClass(n = "String", i = 5)
}

//We can remove this constructor keyword from here also , since we are not using any modifier such as @inject
//Primary constructor is defined with class name in the beginning
//If we prefix the parameter with var/val then they will become the property of class
class myClass constructor(var param1: String) {
    var name: String = "def"//This is the property

    init {//This block is executed to initialize the class, it is part of primary constructor body
        println("INIT bloack called")
        this.name = param1
        println("got property $param1")
    }

    constructor(n: String, i: Int) : this(n) {
        println("Secondary constructor called")
        //Unlike primary constructor, we can not convert parameters to properties
        //It is necessary to give call to the primary constructor
        //This body is executed after init block
    }

    fun fun1() {
        // param1 will be available here since its a property
    }
}