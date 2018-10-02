package lambdaCollectionsFunction


fun main(args: Array<String>) {
    val nums = listOf<Int>(2, 5, 23, 8, 21, 6, 7, 67, 4, 6, 7, 7, 3, 3, 2, 2)

    val myPredicate: (Int) -> Boolean = { num: Int -> num > 20 } // condition

    val c1: Boolean = nums.all(myPredicate) // do all elements satisfy predicate
    println(c1)

    val c2: Boolean = nums.any(myPredicate) // do any elements satisfy predicate
    println(c2)

    val c3: Int = nums.count(myPredicate) // count of elements which satisfy predicate
    println(c3)

    val c4: Int? = nums.find(myPredicate)// return first element which satisfy the predicate
    println(c4)

    val c5: Int? = nums.last(myPredicate)// return first element which satisfy the predicate
    println(c5)

}