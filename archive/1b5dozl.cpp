#include <bits/stdc++.h>
using namespace std;

int n;
string s;

signed main(){
    int t; cin>>t;
    while(t--){
        cin>>n>>s;
        int cnt=0;
        for(int i=0; i<n; ++i)
            if(s[i]=='1')
                cnt++;
        if(cnt%2)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
}