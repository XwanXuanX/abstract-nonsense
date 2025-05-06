#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        if(n==1){
            cout<<1<<'\n';
            continue;
        }
        int ans=2;
        int len=4;
        while(len<n){
            len=(len+1)*2;
            ans++;
        }
        cout<<ans<<'\n';
    }
}