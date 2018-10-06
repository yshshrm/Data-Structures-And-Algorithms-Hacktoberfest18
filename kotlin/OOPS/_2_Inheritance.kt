package OOPS


//By default all the classes,functions,variables in kotlin are public,final.So,they cant be inherited
//Concept of parameter/property while inheriting
//get() set() of properties
//field, open, override keywords
fun main(args: Array<String>) {

    var unknown = Animal("Black")
    unknown.eat()
    unknown.age = 0
    println("AGE___ ${unknown.age}")

    var pet = Dog("white", 8)
    var pet2 = Dog(speed = 5, c = "grey")
    println(pet.color)
    println(pet.param)
}

open class Animal(var color: String) {

    open fun eat() = println("Animal eat")
    open var param = "def param"

    var age = 0
        get() = field * 10//It will be executed when we will access this variable
        set(value) {//It will be executed while assigning values
            if (value > 0) field = value else field = -1
        }
}

//If parent class contains primary constructor with params then derived constructor should also have
class Dog(c: String, var speed: Int) : Animal(c) {
    init {
        this.color = c
    }

    override var param: String = "overrided color"

    constructor(c: String) : this("", 0) {
        //In case we had no primary constructor then we will have to simpley call the super() constructor
    }

    //Override keyword is used to modify parent methods which are open
    override fun eat() {
        println("Dog eat")
        //parent methods/variables can be called using super keyword
        println("Dog called " + super.eat())
        //In case of multiple inheritance , if both parents contain same function then we need to use <className> syntax
        println("Safe " + super<Animal>.eat())
    }

    fun bark() = println("BARK")
}

