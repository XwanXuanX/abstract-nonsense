// Problem: C. Basil's Garden
// Contest: Codeforces - EPIC Institute of Technology Round Summer 2024 (Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1987/C
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

//7 4 4 3 2 3 4 5
//6 4 3 2 1 - 1
// ... +6
//why this works?
//define dp[i] = time needed to the suffix [i,n] to be zero
//obviously dp[n] = a[n]
//consider a[n-1], there are 3 cases:
//    1. a[n-1] > a[n]: we need a[n-1] time
//    2. a[n-1] = a[n]: we need a[n] + 1 time, because the first second will make the suffix
//       [a[n], a[n]-1], which will take a[n] time to be 0. add the 1 second, be a[n] + 1
//    3. a[n-1] < a[n]: we need a[n] - a[n-1] + 1 time for the suffix to be
//       [a[n-1], a[n-1]-1], which will take a[n-1] time to be 0. add the previous part,
//       a[n] - a[n-1] + 1 + a[n-1] = a[n] + 1
//let's assume that dp[i+1] to dp[n] is computed, now compute dp[i]
//there are 3 cases:
//    1. if a[i] needs more time to decrease to 0 than the entire suffix, then just a[i]
//    2. the suffix needs dp[i+1] time to decrease to 0. if a[i] <= dp[i+1], then that means
//       a[i] must be "blocked" for zero or more seconds. blocked means a[i] be the same as a[i+1] at some time,
//       thus a[i] needs one more second for a[i+1] to decrease one more
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    vector<int> dp(n);
    dp[n-1]=a[n-1];
    for(int i=n-2; i>=0; --i) {
        dp[i]=max(dp[i+1]+1, a[i]);
    }
    cout<<dp[0]<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}