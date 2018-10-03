package basics

/**
 * Created by avcbcoder on 16-06-2018.
 */
//We can use if and else blocks to return some values also , last statement is the return value
//When is like a switch block, We dont need to use break statement in this, using else we can define default part
//we can use multiple values seperated by {,} in LHS of cases
fun main(args: Array<String>) {
    //----------------------------
    val x = 5;
    val y = 5;
    var a = if (x > y) {
        println("anything");
        x
    } else {
        println("Last line should return a value")
        y
    }

    //----------------------------
    val v = 10;
    //we have not defined type so it will be of type returned in last statement
    var condition = when (v) {
        10, 20 -> {
            println("10 or 20")
            1
        }
        in 1..50 -> {
            println("less than 50")
            "2"
        }
        100 -> {
            println(100)
            3
        }
        !in 101..200 -> {
            println("out of range")
            4
        }
        else -> {
            println("default")
            5
        }
    }
}