#include<bits/stdc++.h>
using namespace std;

int main()
{
	int l;
	while(scanf("%d",&l),l)
	{
		vector < string > V;
		string s;
		for(int i=0;i<l-1;i++)
		{	
			cin>>s;
			V.push_back(s);	
		}	
		int i,Z=0,Y=0;
		for(i=0;i<V.size();i++)
		{
			if(!V[i].compare("No"))
				continue;
			else
			{
				if(!V[i].compare("+z")&&(!Y||Y==180))
				{	
					if(!Y)
						Z=(Z+90)%360;
					else 
						Z=(Z+270)%360;
					s="z";
				}
				else if(!V[i].compare("-z")&&(!Y||Y==180))			
				{
					if(!Y)
						Z=(Z+270)%360;
					else 
						Z=(Z+90)%360;
					s="z";
				}
				else if(!V[i].compare("+y")&&(!Z||Z==180))			
				{
					if(!Z)
						Y=(Y+90)%360;
					else 
						Y=(Y+270)%360;
					s="y";
				}
				else if(!V[i].compare("-y")&&(!Z||Z==180))			
				{
					if(!Z)
						Y=(Y+270)%360;
					else 
						Y=(Y+90)%360;
					s="y";
				}
				//cout<<"["<<A<<" "<<s<<"]";
			}				
		}
		//printf("%d %d",Z,Y);
		if((!Y&&!Z)||(Y==180&&Z==180))
			printf("+x\n");
		else if((Z==180&&Y==0)||(Z==0&&Y==180))
			printf("-x\n");
		else if(Z==90||Y==90)
			cout<<"+"<<s<<endl;
		else 
			cout<<"-"<<s<<endl;
		/*for(auto k:V)
			cout<<k<<" ";
		cout<<endl;*/
	}
}
