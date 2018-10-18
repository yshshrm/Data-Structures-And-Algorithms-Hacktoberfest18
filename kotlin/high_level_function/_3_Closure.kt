package high_level_function



// In kotlin we can modify outside variables unlike JAVA
// This is called as the closure property
// While passing lambda expression , it automatically assumes the type by looking at
// signature of lambda function in function params.
// ex=> f:(String)->(String)
// while calling => {s->s+"extra"} //s is type of string and return type is also string,
// so we can use string functions also
fun main(args: Array<String>) {
    var result = 5;
    modify { a -> result += a }
    println("Actual value changed $result")
}

fun modify(l: (Int) -> Unit) {
    l(10)
}

