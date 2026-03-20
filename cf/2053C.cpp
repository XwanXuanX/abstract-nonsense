// Problem: C. Bewitching Stargazer
// Contest: Codeforces - Good Bye 2024: 2025 is NEAR
// URL: https://codeforces.com/problemset/problem/2053/C
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

void solve() {
    int n,k; cin>>n>>k;
    auto dfs=[&](auto&& self, int len)->pair<int,int> {
        if(len<k) {
            return {0,0};
        }
        int x=len/2;
        auto[cnt,sum]=self(self,x);
        if(len&1) {
            return {2*cnt + 1, 2*sum + (x+1)*cnt + (x+1)};
        } else {
            return {2*cnt, 2*sum + x*cnt};
        }
    };
    auto[cnt,sum]=dfs(dfs,n);
    cout<<sum<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}