// Problem: C. Remove Exactly Two
// Contest: Codeforces - Codeforces Round 1000 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2063/C
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

//deg 1 -> +0
//deg 2 -> +1
// ...
//deg n -> +(n-1)
//so remove a node with larger degree is better, but is it always?
void solve() {
    int n; cin>>n;
    vector<unordered_set<int>> g(n+1);
    for(int i=0; i<n-1; ++i) {
        int u,v; cin>>u>>v;
        g[u].insert(v),g[v].insert(u);
    }
    vector<int> deg(n+1,0);
    for(auto&& p:g) {
        for(auto&& adj:p) {
            deg[adj]++;
        }
    }
    // debug(print(deg););
    //if you have 1 max, you have to pick it, why?
    //pick it gives you worst (mx-1)+((mn-1)-1) boost, and not pick it gives you maximum 
    //(mn-1)+(mn-1). but mx>=mn+1. so (mn)+(mn-2) = (mn-1)+(mn-1), which is not worse.
    //so always greedily pick the largest degree is correct if there is only one mx
    //if there are more than 1 max, which one you pick?
    int mx=*max_element(deg.begin(),deg.end());
    vector<int> mxs;
    for(int i=1; i<=n; ++i) {
        if(deg[i]==mx) {
            mxs.push_back(i);
        }
    }
    if(mxs.size()==1) {
        deg[mxs[0]]=0;
        for(auto&& adj:g[mxs[0]]) {
            deg[adj]--;
        }
        int comp=1+(*max_element(deg.begin(),deg.end())-1)+(mx-1);
        cout<<comp<<'\n';
        return;
    }
    int done=0;
    for(auto&& u:mxs) {
        done=0;
        for(auto&& x:mxs) {
            if(x==u) continue;
            if(!g[u].count(x)) {
                done=1;
                break;
            }
        }
        if(done) break;
    }
    cout<<(1+(mx-1)+(mx-1)-(!done))<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}