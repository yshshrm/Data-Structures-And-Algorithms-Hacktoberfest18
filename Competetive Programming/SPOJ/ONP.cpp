#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

/*
 * 	coded by aalok_sathe :)
 */

int main()
{
	int tc,pse=0;
	char s,x;
	vector <char> chv;
	int a=0;

	int charct=0;

	stack <char> tru;

	cin>>tc;

	while (tc--)
	{
		chv.clear();
		a=0;
		cin>>s;
		a++;										// (a+b)*(c+d)
		while (a != 0)
		{
			cin>>x;

			if (x=='(')
			{
				a++;
			}
			else{
				if (x==')') {
                        a--;
                        chv.push_back(tru.top());
                        tru.pop();
				}

				else {
					if (x=='+' || x=='-' || x=='*' || x=='/' || x=='^' || x=='%' || x=='_' || x=='|' || x==';' || x=='?'|| x=='~')
					{
						tru.push(x);
					}

					else{
						charct++;
						chv.push_back(x);
					}

				}
			}
		}
		for (int i=0; i<chv.size(); i++)
		{
		cout<<chv.at(i);
		}
	cout<<endl;

	}

	return 0;

}
