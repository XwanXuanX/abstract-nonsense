#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,in; cin>>n;
    map<int,int> cnt;
    for(int i=0; i<n; ++i) cin>>in, cnt[in]++;
    int one=0;
    for(auto& p:cnt) if(p.second==1) one++;
    int ans = ((int)ceil((double)one / 2) * 2) + (cnt.size() - one);
    cout<<ans<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}