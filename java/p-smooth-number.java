import java.lang.*; 
  
class GFG{ 
  
  
static boolean check(int n, int p)  
{ 
    int maximum = -1; 
  
    while ((n % 2) == 0)  
    { 
        maximum = Math.max(maximum, 2); 
        n = n/2; 
    } 
  
    for (int i = 3; i <= Math.sqrt(n); i += 2) 
    { 
        while (n % i == 0)  
        {  
            maximum = Math.max(maximum,i);  
            n = n / i; 
        } 
    } 
  
    if (n > 2) 
        maximum = Math.max(maximum, n); 
      
    return (maximum <= p); 
} 
  

public static void main(String[] args)  
{ 
    int n = 24, p = 7; 
     Scanner sc = new Scanner(System.in);
           n=sc.nextInt();
           p=sc.nextInt(); 
    if (check(n, p)) 
        System.out.println("yes"); 
    else
        System.out.println("no"); 
      
} 
} 