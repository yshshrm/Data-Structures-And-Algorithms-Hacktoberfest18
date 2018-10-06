package OOPS



fun main(args: Array<String>) {
    var p = Person("Ankit")
    p.display()

    //data class
    var s = Student("ankit", 20);
    println(s.name + " " + s.age)

}

class Person {
    var name: String

    constructor(name: String) {
        this.name = name
    }


    fun display() {
        println(this.name)
    }

    override fun toString(): String {
        return "Person(name='$name')"
    }
}

data class Student(val name: String, val age: Int)
