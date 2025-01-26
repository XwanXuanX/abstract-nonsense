#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        string s,t;
        cin>>n>>s>>t;
        int p1=-1;
        for(int i=0; i<n; ++i){
            if(s[i]=='1'){
                p1=i;
                break;
            }
        }
        if(p1==-1){
            cout<<(s==t?"YES":"NO")<<'\n';
            continue;
        }
        // otherwise, the first k character in s must equal t
        int ok=1;
        for(int i=0; i<p1; ++i){
            ok&=(s[i]==t[i]);
        }
        cout<<(ok?"YES":"NO")<<'\n';
    }
}