#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1ll<<60)

#ifndef ONLINE_JUDGE
    #include "debug.hpp"
    #define debug(...) do { __VA_ARGS__ } while (0)
#else
    #define debug(...) do {} while (0)
#endif

//5x5x5x...x5 max is 5^8 which is doable in 2 seconds
void solve() {
    int n,k; cin>>n>>k;
    vector<int> r(n);
    for(int i=0; i<n; ++i) {
        cin>>r[i];
    }
    vector<vector<int>> ans;
    auto ok=[&](vector<int>& d)->bool {
        int sum=accumulate(d.begin(),d.end(),0);
        return sum%k==0;
    };
    auto dfs=[&](auto&& self, vector<int>& d, int i) {
        if(i==n) {
            if(ok(d)) {
                ans.push_back(d);
            }
            return;
        }
        for(int j=1; j<=r[i]; ++j) {
            d[i]=j;
            self(self,d,i+1);
        }
    };
    vector<int> d(n,1);
    dfs(dfs,d,0);
    for(auto&& x:ans) {
        for(auto y:x) {
            cout<<y<<' ';
        }
        cout<<'\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1; //cin>>T;
    while(T--) solve();
}
