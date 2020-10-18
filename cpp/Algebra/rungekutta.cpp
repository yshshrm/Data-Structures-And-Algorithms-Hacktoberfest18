#include<iostream>

/* Defining ordinary differential equation to be solved */
#define f(x,y) (y*y-x*x)/(y*y+x*x)

using namespace std;

#include

/* defining ordinary differential equation to be solved */
#define f(x,y) (y*y-x*x)/(y*y+x*x)

using namespace std;
int main()
{
 float x0, y0, xn, h, yn, k1, k2, k3, k4, k;
 int i, n;

 cout<<"Enter Initial Condition"<< endl;
 cout<<"x0 = ";
 cin>> x0;
 cout<<"y0 = ";
 cin >> y0;
 cout<<"Enter calculation point xn = ";
 cin>>xn;
 cout<<"Enter number of steps: ";
 cin>> n;

 /* Calculating step size (h) */
 h = (xn-x0)/n;

 /* Runge Kutta Method */
 cout<<"\nx0\ty0\tyn\n";
 cout<<"------------------\n";
 for(i=0; i < n; i++)
 {
  k1 = h * (f(x0, y0));
  k2 = h * (f((x0+h/2), (y0+k1/2)));
  k3 = h * (f((x0+h/2), (y0+k2/2)));
  k4 = h * (f((x0+h), (y0+k3)));
  k = (k1+2*k2+2*k3+k4)/6;
  yn = y0 + k;
  cout<< x0<<"\t"<< y0<<"\t"<< yn<< endl;
  x0 = x0+h;
  y0 = yn;
 }

 /* Displaying result */
 cout<<"\nValue of y at x = "<< xn<< " is " << yn;

 return 0;
}

