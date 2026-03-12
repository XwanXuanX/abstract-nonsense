// Problem: C. Max Tree
// Contest: Codeforces - Codeforces Round 1051 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2143/C
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

//you can always achieve the highest for every edge with SOME permutation p
void solve() {
    int n; cin>>n;
    vector<vector<int>> g(n);
    for(int i=0; i<n-1; ++i) {
        int u,v,x,y; cin>>u>>v>>x>>y;
        u--,v--;
        if(x>y) {
            g[u].push_back(v);
        } else {
            g[v].push_back(u);
        }
    }
    //just top sort on the tree to obtain the permutation
    vector<int> deg(n,0);
    for(auto&& p:g) {
        for(auto&& adj:p) {
            deg[adj]++;
        }
    }
    queue<int> que;
    for(int i=0; i<n; ++i) if(deg[i]==0) {
        que.push(i);
    }
    int high=n;
    vector<int> ans(n,0);
    while(que.size()) {
        int sz=que.size();
        for(int _=0; _<sz; ++_) {
            int node=que.front();
            que.pop();
            ans[node]=high--;
            for(auto&& adj:g[node]) {
                deg[adj]--;
                if(deg[adj]==0) {
                    que.push(adj);
                }
            }
        }
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