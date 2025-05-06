#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n),c(n);
    for(int i=0; i<n; ++i)
        cin>>a[i];
    for(int i=0; i<n; ++i)
        cin>>b[i];
    for(int i=0; i<n; ++i)
        cin>>c[i];
    sort(b.begin(),b.end());
    set<int> l(a.begin(),a.end());
    vector<pair<int,int>> seg;
    for(int i=0; i<n; ++i){
        int r=b[i];
        auto it=l.upper_bound(r);
        it--;
        seg.push_back(make_pair(*it,r));
        l.erase(it);
    }
    sort(seg.begin(),seg.end(),
    [](auto& p,auto& q){return (p.second-p.first)>(q.second-q.first);});
    sort(c.begin(),c.end());
    int ans=0;
    for(int i=0; i<n; ++i){
        ans+=(seg[i].second-seg[i].first)*c[i];
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