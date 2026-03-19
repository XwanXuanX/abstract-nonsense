// Problem: A. Penchick and Modern Monument
// Contest: Codeforces - Codeforces Round 987 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2031/A
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
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    vector<int> seg;
    int start=0;
    for(int i=1; i<n; ++i) {
        if(a[i]!=a[i-1]) {
            seg.push_back(i-start);
            start=i;
        }
    }
    seg.push_back(n-start);
    int mx=*max_element(seg.begin(),seg.end());
    cout<<n-mx<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}