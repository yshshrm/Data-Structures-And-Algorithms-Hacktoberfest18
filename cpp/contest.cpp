#include<bits/stdc++.h>
using namespace std;
void fast() {std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}
#define ll long long
#define pb push_back
#define mp1 make_pair
#define ff first
#define ss second
#define vi vector<int>
#define vii vector< pair<int,int> >
#define map1 map<ll int,ll int>
#define vll vector< pair<long long,long long> > 
#define ve vector<ll int>
#define clr(x) memset(x, 0, sizeof(x))
#define loop(x,a,b) for(x=a;x<b;x++)
#define rloop(x,a,b) for(x=a;x>=b;x--)
#define scan(x) scanf("%lld", &x)
#define print(x) printf("%lld", x)
#define itr for(std::map<ll int,ll int>::iterator it=mp.begin(); it!=mp.end(); ++it)
const int mod=1e9+7;
const int maxn=1e6+5;
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	ll int a,b,c,d,k=0,m,n,i,j,sum=0,cnt=0;
	string s;
	cin >> s;
	ve v,v1;
	loop(i,0,s.size())
	{
		if(s[i]=='0')
		{
			v.pb(i);
			sum++;
		}
		else
		{
			v1.pb(i);
			cnt++;
		}
	}
	if(sum==0 || sum<2*cnt)
	{
		cout << -1 << endl;
	}	
	else
	{
		if(2*cnt==sum)
		{
			cout << 1 << endl;
		}
		else
		{
			m=sum-2*cnt;
			cout << m+1 << endl;
			k=1;
		}
		j=0;
		loop(i,0,cnt)
		{
			cout << v[j]+1 << " " << v1[j]+1 << " ";
			j++;
		}
		if(k==1)
		{
			cout << endl;
			loop(i,j+1,v.size())
			{
				cout << v[i]+1 << " ";
			}
		}
	}
}