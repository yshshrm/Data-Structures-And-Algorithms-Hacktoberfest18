#include<bits/stdc++.h>
using namespace std;

main(){
    int a[26];
    //cout<<"Enter heights\n";
    for(int i=0;i<26;i++){
        scanf("%d",&a[i]);
    }
    string s;
    //cout<<"Enter String\n";
    cin>>s;

    int height[s.length()];

    for(int i=0;i<s.length();i++){
        height[i] = a[s[i]-97];
    }
    for(int i=0;i<s.length();i++){
        int max =height[0];
        if(height[i]>max)
            max = height[i];
    }
    return max*s.length();
}
