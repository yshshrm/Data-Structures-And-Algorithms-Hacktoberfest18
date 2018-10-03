package OOPS

/**
 * Created by avcbcoder on 16-06-2018.
 */
// prefix internal means that variable/function/class can only be accessed in same module
// we can not define protected top level functions
open class A {
    private val a = 1; // private and internal are incompatible
    protected val b = 1;// It cannot be accessed in classes except B
    internal val c = 1;
    public val d = 1;
}

class B : A() {
    fun f() {
        // only a can not be accessed here
    }
}