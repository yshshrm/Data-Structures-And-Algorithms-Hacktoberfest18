#include <iostream>

using namespace std;

const int N = 1e5+5;
int par[N];
int siz[N];
void init(){
 for(int i=0;i<N;++i)
     par[i] = i,siz[i] = 1;
}

int getParent(int u){
    return par[u] = (u==par[u]? u: getParent(par[u]));
}

int isSameSet(int u,int v){
        return getParent(u) == getParent(v);
}

void merge(int u,int v){
        u = getParent(u);
        v = getParent(v);
        
        if(u==v)return;
        if(siz[v]>siz[u])
            swap(u,v);
        
        par[v] = u;
        siz[u] += siz[v];
}
int main() {
	
    
    
	return 0;

}
