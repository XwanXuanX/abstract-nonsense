#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    vector<int> a;
    cin>>n;
    a.resize(n);
    for(int i=0; i<n; ++i)
        cin>>a[i];
    int ans=0;
    int p=a[0];
    for(int i=0; i<n; ++i){
        p&=a[i];
        if(p==0){
            ans++;
            if(i<n-1)
                p=a[i+1];
        }
    }
    if(ans==0)
        cout<<1<<'\n';
    else
        cout<<ans<<'\n';
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