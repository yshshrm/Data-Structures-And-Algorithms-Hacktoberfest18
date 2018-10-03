package OOPS


// If a class inherits two interfaces which contain same function name
// this function also needs to be overrided alongwith abstract properties
// parent method can be called if its not abstract using super<interface_name>.{function_name}
fun main(args: Array<String>) {
    var b = Button()
    b.onClick()
}

// In case of interfaces everything is open not final and dont contain any body/initialization block
// There should not be any constructor
interface Listener {
    abstract open var prop: String   //abstract,open keyword is redundant
    fun onClick()
    fun onTouch() = print("Touched")  //Interfaces can contain normal functions too
}

// No primary constructor needed in case of interfaces
class Button : Listener {
    override var prop: String = "Button"

    override fun onClick() {
        // abstract functions can not be called using super.<function_name>
        println("Clicked")
        super.onTouch()
    }
}