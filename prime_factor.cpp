#include <iostream>
#include <cmath>
using namespace std;


void get_primeFactors(int n)
{
     int i;
     double total = n*(n);

     for (i = 2; i <= total; i++)
         while (n % i == 0) {   
             
		    cout << i << ", ";    
          get_primeFactors(n /= i); 
            return;              
	    }
}

void get_primeNumbers(int a)
{
	 int s = 2;       
	double b = (a);
    for (int i = s; i <= b; i++)
    {

    for (int j = 2; j <= i; j++)
     {
        if ((i%j==0)&&(i!=j))    //Condition for not prime
            {
			
                break;
            }

	   else  if (j==i)             //condition for Prime Numbers
           {
                 
			   get_primeFactors(i);
           }
    }
   }
}





int main() 
{
    int n = 0;
    int a = 0;
    cout << "Enter a number : ";
    cin >> n;
    get_primeFactors(n);
    cout << endl;
    cout<<"Enter a another nummber : "<<endl;
    cin>>a;
    get_primeNumbers(a);
    system("PAUSE");
    return 0;




  

}

    
