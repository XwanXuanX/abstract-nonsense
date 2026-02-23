// Problem: C. Neo's Escape
// Contest: Codeforces - Codeforces Round 1022 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2108/C
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

//if mx appears not consecutive, then you have to create a clone in front of every mx
//each clone controls a segment of buttons, so by making clones you are partitioning buttons
//there exists an edge between two index (i->j) IFF a[i]>=a[j] and j-i=1
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    vector<pair<int,int>> seg;
    int start=0;
    for(int i=1; i<n; ++i) {
        if(a[i]!=a[i-1]) {
            seg.push_back({start,i-1});
            start=i;
        }
    }
    seg.push_back({start,n-1});
    //now build g, which is guaranteed to be a DAG
    vector<vector<int>> g(seg.size());
    for(int i=1; i<seg.size(); ++i) {
        if(a[seg[i-1].first]>=a[seg[i].first]) {
            g[i-1].push_back(i);
        }
        if(a[seg[i-1].first]<=a[seg[i].first]){
            g[i].push_back(i-1);
        }
    }
    vector<int> deg(seg.size(),0);
    for(int i=0; i<seg.size(); ++i) {
        for(auto&& adj:g[i]) {
            deg[adj]++;
        }
    }
    int ans=0;
    for(int i=0; i<seg.size(); ++i) {
        if(deg[i]==0) ans++;
    }
    cout<<ans<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}