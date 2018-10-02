package lambdaCollectionsFunction


fun main(args: Array<String>) {

    var allTvf = listOf<tvf>(
            tvf(1, "avf"),
            tvf(20, "bac"),
            tvf(3, "cdf"),
            tvf(4, "abb"),
            tvf(15, "acd")
    )

    var ans: List<String> = allTvf.filter { it.id < 10 && it.str.startsWith("a") }.map { it.str }
    println("Filtered objects ${ans}")

}

data class tvf(var id: Int, var str: String)
