public class GcdOfTwoNumbers {

  private static int gcd(int a, int b) {
    if(a==0)
      return b;
    return gcd(b%a, a);
  }

  public static void main (String args[]) {
    int a=15, b=10;
    System.out.println("GCD of " + a + " and " + b + " is: " + gcd(a,b));
  }

}
