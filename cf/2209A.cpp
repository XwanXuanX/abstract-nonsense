// Problem: A. Flip Flops
// Contest: Codeforces - Codeforces Round 1087 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2209/A
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
    int n,c,k; cin>>n>>c>>k;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    sort(a.begin(),a.end());
    for(int i=0; i<n; ++i) {
        if(a[i]<=c) {
            int diff=c-a[i];
            c+=a[i]+min(diff,k);
            k-=min(diff,k);
        }
    }
    cout<<c<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}