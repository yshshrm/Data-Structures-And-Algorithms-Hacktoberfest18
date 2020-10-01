import java.util.*;
public class Prime
{    
    public static void main(String args[])
    {         
        Scanner sc=new Scanner(System.in);
        int value=sc.nextInt();                                // the number to be checked    
       if((value > 2 && value % 2 == 0) || value == 1) {
           System.out.println("Not a Prime number");
                return ;
        }

        for (int i = 3; i <= (int)Math.sqrt(value); i += 2) {

            if (value % i == 0) {
              System.out.println("Not a Prime number");
                return ;
            }
        }

       System.out.println(" Prime number");
    }    
}   
