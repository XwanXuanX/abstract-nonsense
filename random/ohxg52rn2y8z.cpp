#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    vector<int> a,b;
    cin>>n>>k;
    a.resize(n);
    b.resize(n);
    for(int i=0; i<n; ++i)
        cin>>a[i];
    for(int i=0; i<n; ++i)
        cin>>b[i];
    // for each position we can calculate the maximum exp we can get
    int mx=0,ans=0,pf=0;
    for(int i=0; i<min(n,k); ++i){
        pf+=a[i];
        mx=max(mx,b[i]);
        ans=max(ans,pf+(k-i-1)*mx);
    }
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