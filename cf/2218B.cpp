// Problem: B. The 67th 6-7 Integer Problem
// Contest: Codeforces - Codeforces Round 1090 (Div. 4)
// URL: https://codeforces.com/contest/2218/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
    vector<int> a(7);
    for(int i=0; i<7; ++i) cin>>a[i];
    sort(a.begin(),a.end());
    for(int i=0; i<6; ++i) a[i]=-a[i];
    cout<<accumulate(a.begin(),a.end(),0)<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}