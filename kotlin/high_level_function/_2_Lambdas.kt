package high_level_function

fun main(args: Array<String>) {
    // ............[...Signature...].......[Params]...[MethodBody]
    val myLambda: (Int, Int) -> Int = { a, b -> a + b } // a=>Int,b=>Int , a+b will be returned

    acceptLambda({ s: String, i: Int -> s + i })
    //type is redundant
    acceptLambda({ s, i -> s + i })
    //Another syntax
    acceptLambda(){ s, i -> s + i }
    
    //Another syntax
    acceptLambda{ s, i -> s + i }
}

fun acceptLambda(lamdaFun: (String, Int) -> String) = println(lamdaFun("Hello", 55))
