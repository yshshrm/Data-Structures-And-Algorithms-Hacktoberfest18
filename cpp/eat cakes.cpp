#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool allEaten(vector< pair<int,int> > cakes,int n){
    bool eaten=true;
    for (int i= 0 ; i<n; i++)
    {
        if (cakes[i].second != 0){
            eaten = false;
            break;
        }
    }
    return eaten;
}

int calcMaxCakes(vector< pair<int,int> > cakes,int n){
    int maxcakes=-1;
    for (int i= 0 ; i<n; i++)
    {
        if (cakes[i].second > maxcakes){
            maxcakes=cakes[i].second;
        }
    }
    return maxcakes;
}
int eatingTime(int n, int m, int t, int maxCakes, vector<int> lim, vector< pair<int,int> > cakes){
    //Traverse all friends in decreasing order of limits
    if (maxCakes > 0){
        int i=n-1;
        for (int j=m-1;j>=0;j--){
            //Limit greater than weight of cake
            if (i<0){
                i=0;
                continue;
            }
            if (lim[j]>=cakes[i].first){
                //Reduce quantity of cake by one
                if (cakes[i].second > 0){
                    cakes[i].second-=1;
                    cout<<"Friend "<<j+1<<" ate cake with weight "<<cakes[i].first<<" whose qty remaining is "<<cakes[i].second<<endl;
                    if (cakes[i].second <=0){
                        //Remove cake and reduce n and maybe recalculate i
                        if (i < n-1){
                            for (int t=i;t<=n-2;t++)
                            cakes[t]=cakes[t+1];
                        }
                        cakes.pop_back();
                        n--;
                        i--;
                        cout<<"After removal cakes length="<<cakes.size()<<" n= "<<n<<" i="<<i<<endl;
                    }
                }else{
                    //Remove cake and reduce n and maybe recalculate i
                    i--;
                    j++;
                }
            }else{
                i--;
                j++;
            }
        }
        if (n>0){
            return eatingTime(n,m,t+1,calcMaxCakes(cakes,n) ,lim,cakes);
        }else{
            return t+1;
        }
    }else{
        return t;
    }
}

int calculateTime(int n, int m, int maxCakes, vector<int> lim, vector< pair<int,int> > cakes){
    int t;
    if (cakes.back().first > lim.back()){
        t = -1;
    }else{
        t=eatingTime(n,m,0,maxCakes,lim,cakes);
    }
    
    return t;
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n,m;
	    //n=types of cakes , m=friends of monks
	    cin>>n>>m;
	    vector<int> lim;
	    //Cakes = {weight, number}
        vector< pair<int,int> > cakes;
        //Input limits of friends
        for (int i=0;i<m;i++){
            int l;
            cin>>l;
            lim.push_back(l);
        }
        sort (lim.begin(),lim.end());
        //Input weight of cakes
        for (int i=0;i<n;i++){
            int w;
            cin>>w;
            cakes.push_back({w,0});
        }
        //Input number of cakes
        int maxCakes=-1;
        for (int i=0;i<n;i++){
            int c;
            cin>>c;
            if (maxCakes<c){
                maxCakes=c;
            }
            cakes[i].second=c;
        }
        sort(cakes.begin(),cakes.end());
        
        //Call the function calculate time
        cout<<calculateTime(n,m,maxCakes,lim,cakes)<<endl;
	}
	return 0;
}
