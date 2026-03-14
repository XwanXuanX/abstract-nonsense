// Problem: D. D/D/D
// Contest: Codeforces - Codeforces Round 1025 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2109/D
// Memory Limit: 512 MB
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
    int n,m,l; cin>>n>>m>>l;
    vector<int> a(l);
    vector<vector<int>> g(n);
    for(int i=0; i<l; ++i) cin>>a[i];
    for(int i=0; i<m; ++i) {
        int u,v; cin>>u>>v; u--,v--;
        g[u].push_back(v), g[v].push_back(u);
    }
    queue<pair<int,int>> que;
    vector<int> even(n,-INF), odd(n,-INF);
    que.push({0,0});
    even[0]=0;
    while(que.size()) {
        auto[node, dist]=que.front();
        que.pop();
        assert((even[node]!=-INF) | (odd[node]!=-INF));
        const int nd=dist+1;
        for(auto&& adj:g[node]) {
            if(even[adj]!=-INF && odd[adj]!=-INF) continue;
            if(nd%2) {
                if(odd[adj]!=-INF) continue;
                odd[adj]=nd;
                que.push({adj,nd});
            } else {
                if(even[adj]!=-INF) continue;
                even[adj]=nd;
                que.push({adj,nd});
            }
        }
    }
    //must be connected
    for(int i=0; i<n; ++i) assert(even[i]!=-INF || odd[i]!=-INF);
    vector<int> e,o;
    for(int i=0; i<a.size(); ++i) {
        if(a[i]%2) o.push_back(a[i]); else e.push_back(a[i]);
    }
    //find the longest even and odd length that you can traverse
    int mxe=-INF, mxo=-INF;
    int all=accumulate(e.begin(),e.end(),0ll)+accumulate(o.begin(),o.end(),0ll);
    if(o.size()==0) {
        mxe=all;
    } else {
        int mx=*min_element(o.begin(),o.end());
        if(o.size()%2) {
            mxo=all, mxe=all-mx;
        } else {
            mxe=all, mxo=all-mx;
        }
    }
    string ans;
    for(int i=0; i<n; ++i) {
        int ok=0;
        if(even[i]!=-INF) ok|=(mxe>=even[i]);
        if(odd[i]!=-INF) ok|=(mxo>=odd[i]);
        if(ok) ans.push_back('1'); else ans.push_back('0');
    }
    cout<<ans<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}