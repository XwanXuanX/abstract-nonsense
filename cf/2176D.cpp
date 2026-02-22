// Problem: D. Fibonacci Paths
// Contest: Codeforces - Codeforces Round 1070 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2176/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
#define MOD 998244353

#ifndef ONLINE_JUDGE
    #include "debug.hpp"
    #define debug(...) do { __VA_ARGS__ } while (0)
#else
    #define debug(...) do {} while (0)
#endif

/*
a dp problem:
sort nodes in inc order of a[i], and process them left->right
because it's pointless to process a smaller node AFTER processing a larger node
the fib sequence must be strictly increasing order
*/
void solve() {
    int n,m; cin>>n>>m;
    vector<int> a(n+1);
    vector<pair<int,int>> edges(m);
    vector<vector<int>> in(n+1),out(n+1);
    for(int i=1; i<=n; ++i) cin>>a[i];
    for(int i=0; i<m; ++i) {
        int u,v; cin>>u>>v;
        edges[i]={u,v};
        in[v].push_back(i);
        out[u].push_back(i);
    }
    vector<int> dp(m,1);
    vector<pair<int,int>> as;
    as.reserve(m);
    for(int i=1; i<=n; ++i) {
        as.push_back({a[i],i});
    }
    sort(as.begin(),as.end());
    map<int,int> agg;
    for(auto&& [ai,nod]:as) {
        agg.clear();
        //aggregate all dp with nod as incomming node
        for(auto&& eid:in[nod]) {
            int u=edges[eid].first;
            agg[a[u]]=((agg[a[u]]%MOD)+(dp[eid]%MOD))%MOD;
        }
        //push to all dp with nod as outgoing node
        for(auto&& eid:out[nod]) {
            int u=edges[eid].second;
            if(agg.count(a[u]-a[nod])) {
                dp[eid]=((dp[eid]%MOD)+(agg[a[u]-a[nod]]%MOD))%MOD;
            }
        }
    }
    int ans=0;
    for(int i=0; i<m; ++i) {
        ans=((ans%MOD)+(dp[i]%MOD))%MOD;
    }
    cout<<ans<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}