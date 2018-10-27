#include <iostream>
using namespace std;

//fast expo

int fstExp(int x,int n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return fstExp(x*x,n/2);
    else                             //n is odd
        return x*fstExp(x*x,(n-1)/2);
}

int main(){
	
	int a;
	cout<<"ENTER NO TO THE BASE ";
	cin>>a;	//4
	int n;

	cout<<"ENTER THE POWER ";
	cin>>n;	//532
	
	int p;	
	cout<<"ENTER NO TO WHICH POW(a,n) IS DIVIDED BY ";
	cin>>p;
	
	int t=1;
	while(t*(p-1)<=n){
		t++;
	}
	
	int cons= n - (t-1)*(p-1) ;
	//cout<<cons<<endl; see this is constant term of equation desired power=(t-1)*(p-1) + C
	

	int x=fstExp(a,cons);

	cout<<(x%p);
}
