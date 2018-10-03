package basics;

/**
 * Created by Ankit on 12-06-2018.
 */
//In case of different packages , use import OBVIOUSLY
public class _6_CallKt {
    public static void main(String[] args) {
        int ans = _6_InterOperability_JnKKt.ktFun(2, 3);
        System.out.print(ans);
    }
    public static int javaFun(int a,int b){
        return a+b;
    }
}
