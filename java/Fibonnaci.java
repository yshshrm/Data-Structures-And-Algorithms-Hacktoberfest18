public class Fibonnaci() {
  public static int fib(int a) {
    if(a == 0) 
      return 0;
    else if (a == 1) 
      return 1;
    else 
      return fib(a-1) + fib(a-2);
  }
}
