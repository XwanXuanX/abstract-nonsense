// Problem: B. Team Training
// Contest: Codeforces - Codeforces Round 1013 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2091/B
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

//5 3 3 2 2 
//5
//3
//3
//2
void solve() {
    int n,x; cin>>n>>x;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    sort(a.begin(),a.end(),greater<int>());
    int ans=0, pr=-1;
    for(int i=0; i<n; ++i) {
        int mn=a[i], len=i-pr, prod=mn*len;
        // debug(print(prod););
        if(prod>=x) {
            ans++;
            pr=i;
        }
    }
    cout<<ans<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}