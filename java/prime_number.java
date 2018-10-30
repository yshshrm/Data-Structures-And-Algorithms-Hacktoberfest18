public class Prime
{    
    public static void main(String args[])
    {    
        int i,m=0,flag=0;      
        int n=3;//it is the number to be checked    
        m=n/2;      
        if(n==0||n==1)
        {  
          System.out.println(n+" is not prime number");      
        }
        else if (n==2)
        {
            System.out.println(n+" is prime number");
        }
        else
        {  
          for(i=3;i<=m;i+=2)
          {      
            if(n%i==0)
            {      
              System.out.println(n+" is not prime number");      
              flag=1;      
              break;      
            }      
          }      
        if(flag==0)  { System.out.println(n+" is prime number"); }  
        }//end of else  
    }    
}   
