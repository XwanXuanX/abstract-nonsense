#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
vector<int> a,b;
const int INF=LLONG_MAX;

void solve(){
    cin>>n>>m;
    a.assign(n,0), b.assign(n,0);
    for(int i=0; i<n; ++i)
        cin>>a[i];
    for(int i=0; i<n; ++i)
        cin>>b[i];

    int ans=INF, tot=0;
    for(int i=n-1; i>=0; --i){
        if(i<m)
            ans=min(ans, tot+a[i]);
        tot += min(a[i],b[i]);
    }

    cout<<ans<<'\n';
}

signed main(){
    int t; cin>>t;
    while(t--) solve();
}