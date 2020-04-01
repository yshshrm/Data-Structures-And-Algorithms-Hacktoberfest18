#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <set>
#include <cmath>
#include <cstring> 
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include <ctime>
#include <assert.h>
// The above are various header files to implement the Standard Template library

using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi>vvi;
typedef vector<string> vs;
typedef map<string,int> msi;
typedef map<int,int>mii;
/* The aim of this sorting algorithm is to sort the given array of integers in a wave pattern in the most efficient manner possible.
*/   

int main()
{
  ios_base::sync_with_stdio(false);//For fast Input/Output
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin>>n;
  
  int *a=new int[n];//Dynamic memory allocation of an array of size n.
  
  for(int i=0;i<n;i++)
  {
	  cin>>a[i];
  }

  //Go to every second element, try to create a peak.

  for(int i=0;i<n;i+=2)
  {
	  //Check for the left element
	  if(i>0 && a[i-1]>a[i])
	  {
		  swap(a[i],a[i-1]);
	  }

	  //Check for the right element
	  if(i<=n-2 && a[i+1]>a[i])
	  {
		  swap(a[i],a[i+1]);
	  }
  }

  //Printing the elements
  for(int i=0;i<n;i++)
  {
	cout<<a[i]<<" ";
  }

  cout<<endl;


 return 0;
}
