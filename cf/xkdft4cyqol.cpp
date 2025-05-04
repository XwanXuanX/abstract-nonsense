#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    int c0=0;
    for(int i=0; i<n; ++i){
        if(s[i]=='0')
            c0++;
    }
    int c1=n-c0;
    for(int i=0; i<n; ++i){
        if(s[i]=='0'){
            if(c1){
                c1--;
            }else{
                cout<<c0<<'\n';
                return;
            }
        }else{
            if(c0){
                c0--;
            }else{
                cout<<c1<<'\n';
                return;
            }
        }
    }
    cout<<0<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
}