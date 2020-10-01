struct suffixArray{
    string s;
    int len;
    vector<int> iSA,SA;
    vector<int> cnt,next_gen,lcp;
    vector<vector<int>> LCP;
    vector<bool> bh,b2h,m_arr;
    suffixArray(string s=""){
        if(s!="")init(s);
    }
    void init(string sinp){
        s = sinp;
        len = sinp.size();
        iSA.resize(len); SA.resize(len);
        cnt.resize(len); next_gen.resize(len); lcp.resize(len);
        LCP.resize(len);
        bh.resize(len); b2h.resize(len); m_arr.resize(len);
        for(int i = 0; i < len; i++)LCP[i].resize(22);
        SuffixSort();
    }
    bool smaller_first_char(int a, int b){
        return s[a] < s[b];
    }
    void SuffixSort(){
        for (int i=0; i<len; ++i)SA[i] = i;
        vector<pair<char,int> > arrr;
        for(int i = 0; i < len; i++)arrr.pb(mp(s[SA[i]],SA[i]));
        sort(arrr.begin(),arrr.end());
        for(int i = 0; i < len; i++)SA[i] = arrr[i].sec;

        for (int i=0; i<len; ++i){
            bh[i] = i == 0 || s[SA[i]] != s[SA[i-1]];
            b2h[i] = false;
        }
        for (int h = 1; h < len; h <<= 1){
            int buckets = 0;
            for (int i=0, j; i < len; i = j){
                j = i + 1;
                while (j < len && !bh[j]) j++;
                next_gen[i] = j;
                buckets++;
            }
            if (buckets == len) break;
            for (int i = 0; i < len; i = next_gen[i]){
                cnt[i] = 0;
                for (int j = i; j < next_gen[i]; ++j){
                    iSA[SA[j]] = i;
                }
            }
            cnt[iSA[len - h]]++;
            b2h[iSA[len - h]] = true;
            for (int i = 0; i < len; i = next_gen[i]){
                for (int j = i; j < next_gen[i]; ++j){
                    int s = SA[j] - h;
                    if (s >= 0){
                        int head = iSA[s];
                        iSA[s] = head + cnt[head]++;
                        b2h[iSA[s]] = true;
                    }
                }
                for (int j = i; j < next_gen[i]; ++j){
                    int s = SA[j] - h;
                    if (s >= 0 && b2h[iSA[s]]){
                        for (int k = iSA[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
                    }
                }
            }
            for (int i=0; i<len; ++i){
                SA[iSA[i]] = i;
                bh[i] = bh[i] | b2h[i];
            }
        }
        for (int i=0; i<len; ++i){
            iSA[SA[i]] = i;
        }
    }
    void InitLCP(int n){
        for (int i=0; i<n; ++i)
            iSA[SA[i]] = i;
        lcp[0] = 0;
        for (int i=0, h=0; i<n; ++i) {
            if (iSA[i] > 0) {
                int j = SA[iSA[i]-1];
                while (i + h < n && j + h < n && s[i+h] == s[j+h])
                    h++;
                lcp[iSA[i]] = h;
                if (h > 0)
                    h--;
            }
        }
    }
    void ConstructLCP(){
        InitLCP(len);
        for(int i = 0;i<len;++i)
            LCP[i][0] = lcp[i];
        for(int j = 1;(1<<j)<=len;++j){
            for(int i = 0;i+(1<<j)-1<len;++i){
                if(LCP[i][j-1]<=LCP[i+ ( 1<<(j-1) )][j-1])
                    LCP[i][j] = LCP[i][j-1];
                else
                    LCP[i][j] = LCP[i+(1<<(j-1))][j-1];
            }
        }
    }
    int GetLCP(int x, int y) {
        if(x == y) return len-SA[x];
        if(x > y) swap(x,y);
        int log = 0;
        while((1<<log)<=(y-x)) ++log;
        --log;
        return min(LCP[x+1][log],LCP[y-(1<<log)+1][log]);
    }
    void PrintSA(){
        pr(SA);pr(iSA);pr(lcp);
    }
};
/*
5
abcab
SA:[3 0 4 1 2 ]
iSA:[1 3 4 0 2 ]
lcp:[0 2 0 1 0 ]
*/
//another implementation

vector<int> suffix_array(string s)
{
    int n = s.size(), N = n + 256;
    vector<int> sa(n), ra(n);
    for(int i = 0; i < n; i++) sa[i] = i, ra[i] = s[i];
    for(int k = 0; k < n; k ? k *= 2 : k++)
    {
        vector<int> nsa(sa), nra(n), cnt(N);
        for(int i = 0; i < n; i++) nsa[i] = (nsa[i] - k + n) % n;
        for(int i = 0; i < n; i++) cnt[ra[i]]++;
        for(int i = 1; i < N; i++) cnt[i] += cnt[i - 1];
        for(int i = n - 1; i >= 0; i--) sa[--cnt[ra[nsa[i]]]] = nsa[i];

        int r = 0;
        for(int i = 1; i < n; i++)
        {
            if(ra[sa[i]] != ra[sa[i - 1]]) r++;
            else if(ra[(sa[i] + k) % n] != ra[(sa[i - 1] + k) % n]) r++;
            nra[sa[i]] = r;
        }
        ra = nra;
    }
    return sa;
}

vector<int> kasai(string s, vector<int> sa)
{
    int n = s.size(), k = 0;
    vector<int> ra(n), lcp(n);
    for(int i = 0; i < n; i++) ra[sa[i]] = i;
    for(int i = 0; i < n; i++)
    {
        if(k) k--;
        if(ra[i] == n - 1) {k = 0; continue;}
        int j = sa[ra[i] + 1];
        while(k < n && s[(i + k) % n] == s[(j + k) % n]) k++;
        lcp[ra[i]] = k;
        if(ra[(sa[ra[i]] + 1) % n] > ra[(sa[ra[j]] + 1) % n]) k = 0;
    }
    return lcp;
}


//impleme
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mod 1000000007
#define pb emplace_back
#define mp make_pair
#define fi first
#define sec second
typedef long long ll;
typedef long double  ld;
#define pii pair<ll,ll> 
#define vi vector< ll > 
#define vvi vector< vi > 
#define vpi vector< pii > 
#define vvpi vector< vpi > 
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define test(t) ll t;cin>>t;while(t--)
#define mem(a,b) memset(a,b,sizeof(a))
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)
#define all(arr) arr.begin(),arr.end()
#define fr(i,n) for(ll i=0;i<(n);++i)
#define rep(i,a,b) for(ll i=a;i<=b;++i)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define remin(a,b) (a=min((a),(b)))
#define remax(a,b) (a=max((a),(b)))
#ifndef ONLINE_JUDGE
#define debarr(a,n)cerr<<#a<<":";for(int i=0;i<n;i++)cerr<<a[i]<<" ";cerr<<endl;
#define debmat(mat,row,col)cerr<<#mat<<":\n";for(int i=0;i<row;i++){for(int j=0;j<col;j++)cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...)dbs(#__VA_ARGS__,__VA_ARGS__)
template<class S,class T>ostream &operator<<(ostream &os,const pair<S,T> &p){return os<<"("<<p.first<<","<<p.second<<")";}
template<class T>ostream &operator<<(ostream &os,const vector<T> &p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>ostream &operator<<(ostream &os,const set<T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>ostream &operator<<(ostream &os,const multiset<T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class S,class T>ostream &operator<<(ostream &os,const map<S,T>&p){os<<"[";for(auto&it:p)os<<it<<" ";return os<<"]";}
template<class T>void dbs(string str,T t){cerr<<str<<":"<<t<<"\n";}
template<class T,class...S>void dbs(string str,T t,S... s){int idx=str.find(',');cerr<<str.substr(0,idx)<<":"<<t<<",";dbs(str.substr(idx+1),s...);}
#else
#define pr(...){}
#define debarr(a,n){}
#define debmat(mat,row,col){}
#endif
ll power(ll x,ll y){ll res = 1;while(y){if(y&1) res = (res*x)%mod;y=y/2,x=(x*x)%mod;}return res%mod;}


struct suffixArray{
    string s;
    int len;
    vector<int> iSA,SA;
    vector<int> cnt,next_gen,lcp;
    vector<vector<int>> LCP;
    vector<bool> bh,b2h,m_arr;
    suffixArray(string s=""){
        if(s!="")init(s);
    }
    void init(string sinp){
        s = sinp;
        len = sinp.size();
        iSA.resize(len); SA.resize(len);
        cnt.resize(len); next_gen.resize(len); lcp.resize(len);
        LCP.resize(len);
        bh.resize(len); b2h.resize(len); m_arr.resize(len);
        for(int i = 0; i < len; i++)LCP[i].resize(22);
        SuffixSort();
    }
    bool smaller_first_char(int a, int b){
        return s[a] < s[b];
    }
    void SuffixSort(){
        for (int i=0; i<len; ++i)SA[i] = i;
        vector<pair<char,int> > arrr;
        for(int i = 0; i < len; i++)arrr.pb(mp(s[SA[i]],SA[i]));
        sort(arrr.begin(),arrr.end());
        for(int i = 0; i < len; i++)SA[i] = arrr[i].sec;

        for (int i=0; i<len; ++i){
            bh[i] = i == 0 || s[SA[i]] != s[SA[i-1]];
            b2h[i] = false;
        }
        for (int h = 1; h < len; h <<= 1){
            int buckets = 0;
            for (int i=0, j; i < len; i = j){
                j = i + 1;
                while (j < len && !bh[j]) j++;
                next_gen[i] = j;
                buckets++;
            }
            if (buckets == len) break;
            for (int i = 0; i < len; i = next_gen[i]){
                cnt[i] = 0;
                for (int j = i; j < next_gen[i]; ++j){
                    iSA[SA[j]] = i;
                }
            }
            cnt[iSA[len - h]]++;
            b2h[iSA[len - h]] = true;
            for (int i = 0; i < len; i = next_gen[i]){
                for (int j = i; j < next_gen[i]; ++j){
                    int s = SA[j] - h;
                    if (s >= 0){
                        int head = iSA[s];
                        iSA[s] = head + cnt[head]++;
                        b2h[iSA[s]] = true;
                    }
                }
                for (int j = i; j < next_gen[i]; ++j){
                    int s = SA[j] - h;
                    if (s >= 0 && b2h[iSA[s]]){
                        for (int k = iSA[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
                    }
                }
            }
            for (int i=0; i<len; ++i){
                SA[iSA[i]] = i;
                bh[i] = bh[i] | b2h[i];
            }
        }
        for (int i=0; i<len; ++i){
            iSA[SA[i]] = i;
        }
    }
    void InitLCP(int n){
        for (int i=0; i<n; ++i)
            iSA[SA[i]] = i;
        lcp[0] = 0;
        for (int i=0, h=0; i<n; ++i) {
            if (iSA[i] > 0) {
                int j = SA[iSA[i]-1];
                while (i + h < n && j + h < n && s[i+h] == s[j+h])
                    h++;
                lcp[iSA[i]] = h;
                if (h > 0)
                    h--;
            }
        }
    }
    void ConstructLCP(){
        InitLCP(len);
        for(int i = 0;i<len;++i)
            LCP[i][0] = lcp[i];
        for(int j = 1;(1<<j)<=len;++j){
            for(int i = 0;i+(1<<j)-1<len;++i){
                if(LCP[i][j-1]<=LCP[i+ ( 1<<(j-1) )][j-1])
                    LCP[i][j] = LCP[i][j-1];
                else
                    LCP[i][j] = LCP[i+(1<<(j-1))][j-1];
            }
        }
    }
    int GetLCP(int x, int y) {
        if(x == y) return len-SA[x];
        if(x > y) swap(x,y);
        int log = 0;
        while((1<<log)<=(y-x)) ++log;
        --log;
        return min(LCP[x+1][log],LCP[y-(1<<log)+1][log]);
    }
    void PrintSA(){
        pr(SA);pr(iSA);pr(lcp);
    }
};

/*
5
abcab
SA:[3 0 4 1 2 ]
iSA:[1 3 4 0 2 ]
lcp:[0 2 0 1 0 ]
*/

vpi t[2000008];

void build(int index, int low, int high){
    t[index].clear();
    if(low==high)
        return;
    int mid = (low+high)/2;
    build(2*index,low,mid);
    build(2*index+1,mid+1,high);
}

void update(int index ,int low, int high, int lq, int rq, int lval, int iSA){
    if(low>rq or lq>high)
        return;
    if(lq<=low and high<=rq)
    {
        while(!t[index].empty() and t[index].back().sec>iSA)
            t[index].pop_back();
        t[index].pb(lval,iSA);
        return;
    }
    int mid = (low+high)/2;
    update(2*index,low,mid,lq,rq,lval,iSA);
    update(2*index+1,mid+1,high,lq,rq,lval,iSA);
}

int query(int index, int low, int high, int rq, int lmax){
    if(rq<low or rq>high)
        return mod;
    int ans=mod;

    if(!t[index].empty())
    {
        int lo = -1;
        for(int step = t[index].size();step;step>>=1)
        {
            while(lo+step<t[index].size() and t[index][lo+step].fi>lmax)lo+=step;
        }
        lo++;
        if(lo<t[index].size())
        {
            ans=t[index][lo].sec;
        }
    }
    if(low==high)
        return ans;
    int mid = (low+high)/2;
    ans = min(ans,query(2*index,low,mid,rq,lmax));
    ans = min(ans,query(2*index+1,mid+1,high,rq,lmax));
    return ans;
}

signed main()
{
    fast;
    test(t)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        suffixArray suf(s);
        suf.ConstructLCP();
        int loVal[n];
        fr(i,n)
        {
            loVal[suf.SA[i]] = suf.SA[i];
            loVal[suf.SA[i]] = max(loVal[suf.SA[i]],suf.SA[i]+suf.lcp[i]);
            if(i<n-1)
                loVal[suf.SA[i]] = max(loVal[suf.SA[i]],suf.SA[i]+suf.lcp[i+1]);
        }
        int q;
        cin>>q;
        vector< pair< pii, pii > > offline[n];
        pii ans[q];
        fr(i,q)
        {
            int l,r,k;
            cin>>l>>r>>k;
            l--;r--;
            ans[i]=mp(-1,-1);
            if(r-l+1>=k)
                offline[l].pb(mp(r,k),mp(i,r-k+1));
        }
        build(1,0,n-1);
        per(i,n-1,0)
        {
            if(loVal[i]<n)
            {
                update(1,0,n-1,loVal[i],n,i,suf.iSA[i]);
            }
            for(auto &v:offline[i])
            {
                int myVal = query(1,0,n-1,v.fi.fi,v.sec.sec);
                if(myVal>=n)
                {
                    continue;
                }
                else
                {
                    int pos = suf.SA[myVal];
                    ans[v.sec.fi] = mp(pos+1,1+max((ll)loVal[pos],pos+v.fi.sec-1));
                }
            }
        }
        fr(i,q)
            cout<<ans[i].fi<<" "<<ans[i].sec<<"\n";
    }
    
}
