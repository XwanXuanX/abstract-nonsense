// Problem: A. Tender Carpenter
// Contest: Codeforces - Good Bye 2024: 2025 is NEAR
// URL: https://codeforces.com/problemset/problem/2053/A
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
    int ok=0;
    for(int i=1; i<n; ++i) {
        int mn=min(a[i-1],a[i]), mx=max(a[i-1],a[i]);
        if(mn+mn>mx) {
            ok|=1;
        }
    }
    if(ok) cout<<"YES\n"; else cout<<"NO\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}