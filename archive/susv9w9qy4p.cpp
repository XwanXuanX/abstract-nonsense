#include <bits/stdc++.h>
using namespace std;

int n;
string s,r;

void solve(){
    cin>>n>>s>>r;
    int c0=0, c1=0;
    for(int i=0; i<n; ++i){
        if(s[i]=='0')
            c0++;
        else
            c1++;
    }

    for(int i=0; i<n-1; ++i){
        if(c1==0 || c0==0){
            cout<<"NO\n";
            return;
        }
        c1--, c0--;
        if(r[i]=='0')
            c0++;
        else
            c1++;
    }

    cout<<"YES\n";
}

signed main(){
    int t; cin>>t;
    while(t--) solve();
}