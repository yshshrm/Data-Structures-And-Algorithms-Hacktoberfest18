#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int main()
{
    string st1 = "ROHIT";
    string arr[] = {"AMAR" , "AMARJEET", "BHEEM" , "BIMAL" , "CHAND" ,"CHARU", "DEV" , "DHAWAN","ESHA","GANESH" , "ROHIT" , "ZAHID"};
    int l = (int)(arr[0].at(0));
    int h = (int)(arr[11].at(0));
    int x = (int)(st1.at(0));
    int low =0 , hi = 11 , pos=0;
    while(x<=h && x >=l && l<h)
    {
        pos = low + ((hi-low) * (x-l)) /(h-l);
        if(arr[pos] == st1)
        {
            cout<<"\nFound at pos:- "<<(pos+1);
            break;
        }
        else
        {
            if(arr[pos] > st1)
                hi = pos-1;
            else
                low = pos +1;
        }
    }
    return 0 ;
}
