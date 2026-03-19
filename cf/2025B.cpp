// Problem: B. Binomial Coefficients, Kind Of
// Contest: Codeforces - Educational Codeforces Round 170 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/2025/B
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
#define MOD (int)(1e9+7)

#ifndef ONLINE_JUDGE
    #include "debug.hpp"
    #define debug(...) do { __VA_ARGS__ } while (0)
#else
    #define debug(...) do {} while (0)
#endif

void solve() {
    int t; cin>>t;
    vector<int> a(t),b(t);
    for(int i=0; i<t; ++i) cin>>a[i];
    for(int i=0; i<t; ++i) cin>>b[i];
    vector<int> p2(1e6,0);
    p2[0]=1;
    for(int i=1; i<1e6; ++i) {
        p2[i]=((p2[i-1]%MOD)*(2%MOD))%MOD;
    }
    auto handle=[&](int n,int k)->int {
        if(k==0 || k==n) {
            return 1;
        }
        return p2[k];
    };
    for(int i=0; i<t; ++i) {
        cout<<handle(a[i],b[i])<<'\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1;
    while(T--) solve();
}