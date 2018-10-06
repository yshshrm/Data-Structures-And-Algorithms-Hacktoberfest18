//@file:JvmName("CustomName")//It should be on the top

package basics


fun main(args: Array<String>) {
    println(_6_CallKt.javaFun(5,6))
}

fun ktFun(a: Int, b: Int): Int {
    return a + b
}

//Since There is no concpet of default params in java , so @jvmoverloads will make multiple functions
@JvmOverloads
fun area(l:Int,b:Int,h:Int=1)=l*b*h

//Compiler follow simple Convention for calling functions of Kotlin class i.e (nameOfFile+kt) ,
// we can change it using annotations @

/*This code will be converted into this

     public class InterOperability_JnKkt{
            public static void main(String[]args){

            }
            public static ktFun(int a,int b){
                   return a+b;
            }
     }
*/