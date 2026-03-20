// Problem: G. Tree Destruction
// Contest: Codeforces - Codeforces Round 991 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2050/G
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
    vector<vector<int>> g(n);
    for(int i=0; i<n-1; ++i) {
        int a,b; cin>>a>>b; a--,b--;
        g[a].push_back(b),g[b].push_back(a);
    }
    vector<int> deg(n,0);
    for(int i=0; i<n; ++i) {
        deg[i]=g[i].size();
    }
    int ans=0;
    // debug(print(deg);); // seems about right
    auto dfs=[&](auto&& self,int nod,int par)->int {
        //at each node there are 4 choices (for a binary tree):
        //1. self
        //2. self + left
        //3. self + right
        //4. self + left + right
        if(g[nod].size()==1 && g[nod][0]==par) {
            return 1;
        }
        vector<int> res(g[nod].size());
        for(int i=0; i<g[nod].size(); ++i) {
            const auto adj=g[nod][i];
            if(adj==par) continue;
            res[i]=self(self,adj,nod);
        }
        sort(res.begin(),res.end(),greater<int>());
        int dbl=0;       //double
        int mx=deg[nod]; //self
        if(res.size()>0) mx=max(mx,res[0]+deg[nod]-2); //single
        if(res.size()>1) dbl=res[0]+res[1]+deg[nod]-4; //double
        ans=max(ans,max(mx,dbl));
        // debug(print(nod+1,par+1,mx););
        return mx; //dbl cannot propogate further, only return self or single
    };
    dfs(dfs,0,-1);
    cout<<ans<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}