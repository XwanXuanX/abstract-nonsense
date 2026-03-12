// Problem: A. Double Perspective
// Contest: Codeforces - Codeforces Round 1040 (Div. 1)
// URL: https://codeforces.com/problemset/problem/2129/A
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

struct DSU {
    vector<int> p;
    DSU(int n) {
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
    }
    int find(int i) {
        return p[i] == i ? i : p[i] = find(p[i]);
    }
    bool unite(int i, int j) {
        int r1 = find(i), r2 = find(j);
        if (r1 != r2) {
            p[r1] = r2;
            return true;
        }
        return false;
    }
};

struct Edge {
    int u, v, w;
    bool operator<(const Edge& o) const { return w < o.w; }
};

//isn't this just MST of G?
void solve() {
    int n; cin>>n;
    vector<Edge> e;
    for(int i=0; i<n; ++i) {
        int a,b; cin>>a>>b;
        a--,b--;
        e.push_back({a,b,b-a});
    }
    vector<pair<Edge,int>> ee;
    for(int i=0; i<n; ++i) {
        ee.push_back({e[i],i+1});
    }
    sort(ee.begin(),ee.end(),greater<pair<Edge,int>>());
    DSU dsu(2*n);
    vector<int> ans;
    for(auto&& [x,i]:ee) {
        if(dsu.unite(x.u,x.v)) {
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<'\n';
    for(int i=0; i<ans.size(); ++i) {
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