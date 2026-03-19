// Problem: E. Kirei Attacks the Estate
// Contest: Codeforces - Codeforces Round 1027 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2114/E
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

#ifndef ONLINE_JUDGE
    #include "debug.hpp"
    #define debug(...) do { __VA_ARGS__ } while (0)
#else
    #define debug(...) do {} while (0)
#endif

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    vector<vector<int>> g(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    for(int i=0; i<n-1; ++i) {
        int u,v; cin>>u>>v; u--,v--;
        g[u].push_back(v),g[v].push_back(u);
    }
    vector<int> ans(n);
    vector<pair<int,int>> dp(n,{INF,-INF}); //{min, max}
    ans[0]=a[0];
    dp[0]={a[0],a[0]};
    auto dfs=[&](auto&& self,int nod,int par)->void {
        auto[mn,mx]=dp[par];
        ans[nod]=max(a[nod]-mn,a[nod]);
        dp[nod].second=max(a[nod]-mn,a[nod]);
        dp[nod].first=min(a[nod]-mx,a[nod]);
        for(auto&& adj:g[nod]) {
            if(adj==par) continue;
            self(self,adj,nod);
        }
    };
    for(int adj:g[0]) {
        dfs(dfs,adj,0);
    }
    for(int i=0; i<n; ++i) {
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}