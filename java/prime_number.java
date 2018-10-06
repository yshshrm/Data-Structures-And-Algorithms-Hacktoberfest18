public class Prime
{    
    public static void main(String args[])
    {          
        int value=3;//it is the number to be checked    
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
