// Problem: D. Rae Taylor and Trees (easy version)
// Contest: Codeforces - Codeforces Round 1065 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2171/D
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

//1. needs to be connected
//2. needs to have exactly n-1 edges
//1 3 4 5 2 6
// (1 3), (1 4), (1 5), (1 2), (1 6)
//3 4 1 2
// (3 4), (1 2), no other edges -> not a tree
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    int i1=-1;
    for(int i=0; i<n; ++i) if(a[i]==1) {
        i1=i;
        break;
    }
    assert(i1>=0);
    set<int> sat;
    for(int i=i1; i<n; ++i) {
        sat.insert(a[i]);
    }
    assert(sat.size()>0);
    set<pair<int,int>> front;
    for(int i=0; i<i1; ++i) {
        front.insert({a[i],i});
    }
    while(front.size()) {
        auto bg=front.begin();
        auto[ai,i]=*bg;
        //sat.rbegin() is the max in the sat set
        //and ai is the min in the front set
        //if this pair can't be satisfied, then no other pair can
        if(*sat.rbegin()<ai) {
            cout<<"No\n";
            return;
        }
        for(int j=i; j<i1; ++j) {
            sat.insert(a[j]);
            front.erase({a[j],j});
        }
        i1=i;
    }
    cout<<"Yes\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}