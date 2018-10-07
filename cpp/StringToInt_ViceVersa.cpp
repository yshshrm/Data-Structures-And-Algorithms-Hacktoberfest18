//convert number to string
/*
#include <iostream>
#include <string>
using namespace std;

int main()
{   int x;
    string n;
    cin>>n;
    x=atoi(n.c_str());
    cout << x <<endl << x+1;
   return 0;
}*/
    //----------------------------------------------------------------------------------------------------------
//convert number to string
#include <iostream>
#include <String>
#include <iomanip>
#include <locale>
#include <sstream>
using namespace std;
int main()
{   int x;
    string n;
    ostringstream kz;
    cin >> x;
    kz << x;
    n=kz.str();
    cout << n[2];
    kz.str("");
   return 0;
}
