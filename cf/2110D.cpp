// Problem: D. Fewer Batteries
// Contest: Codeforces - Codeforces Round 1026 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2110/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#if defined(__GNUC__) && !defined(__clang__)
    #pragma GCC optimize("Ofast,unroll-loops")
    #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma")
#endif
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

//binary search for the ans
//since all batteries are recharged at every node, the quickly we reach mid batteries the better
//thus the greedy approach
void solve() {
    int n,m; cin>>n>>m;
    vector<int> a(n+1,0);
    vector<vector<pair<int,int>>> g(n+1);
    for(int i=1; i<=n; ++i) cin>>a[i];
    for(int i=0; i<m; ++i) {
        int u,v,w; cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    auto check=[&](int ub)->bool {
        //it's actually finding the "longest path" to a node
        //ALSO NOTE: g is a DAG! READ THE PROBLEM PROPERLY!
        vector<int> dp(n+1,-1);
        dp[1]=min(a[1],ub);
        //by traversing from small node to larger node, this is implicitly top sort order!
        //because s<t
        for(int i=1; i<=n; ++i) {
            //not reachable
            if(dp[i]==-1) continue;
            for(auto&& [v,need]:g[i]) {
                if(dp[i]<need) continue;
                dp[v]=max(dp[v],min(ub,dp[i]+a[v]));
            }
        }
        return dp[n]>=0;
    };
    int r=accumulate(a.begin(),a.end(),0ll),l=0,ans=INF;
    while(l<=r) {
        int mid=(l+r)>>1;
        if(check(mid)) {
            ans=min(ans,mid);
            r=mid-1;
        } else {
            l=mid+1;
        }
    }
    cout<<(ans==INF?-1:ans)<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}