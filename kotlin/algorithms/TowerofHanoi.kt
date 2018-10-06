fun hanoi(n: Int, source: Char, helper: Char, target: Char){
    if(n == 1){
        println("Move 1 from " + source + " to " + target)
        return
    }
    hanoi(n-1, source, target, helper)
    println("Move " + n + " from " + source + " to " + target)
    hanoi(n-1, helper, source, target)
}
fun main(args: Array<String>) {
    val n = 4
    //Move n Disks from A to C
    hanoi(n, 'A', 'B', 'C')
}
