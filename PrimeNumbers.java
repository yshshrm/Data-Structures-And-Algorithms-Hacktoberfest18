public class PrimeNumbers
{    
    public static void main(String args[])
    {    
        int i,b=0,f=0;      
        int a=3;//it is the number to be checked    
        b=a/2;      
        if(a==0||a==1)
        {  
          System.out.println(a+" is not prime number");      
        }
        else
        {  
          for(i=2;i<=b;i++)
          {      
            if(a%i==0)
            {      
              System.out.println(a+" is not prime number");      
              f=1;      
              break;      
            }      
          }      
        if(f==0)  { System.out.println(a+" is prime number"); }  
        }//end of else  
    }    
}
