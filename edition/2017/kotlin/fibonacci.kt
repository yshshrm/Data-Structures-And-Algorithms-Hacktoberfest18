fun main(args: Array<String>) {
    val fibonacci = Fibonacci()
   	println(fibonacci.execute(5))
}

class Fibonacci {
     
    fun execute(n: Int) : List<Int> {
        return (1..n).map { fib(it) }
    }
    
    private fun fib(n: Int) : Int = when (n) {
        1 -> n
        else -> fib(n - 1) + fib(n - 2)
    }
}