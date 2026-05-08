// Problem: C. The 67th Permutation Problem
// Contest: Codeforces - Codeforces Round 1090 (Div. 4)
// URL: https://codeforces.com/contest/2218/problem/C
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

//1 2 3 4 5 6 7 8 9
//1 . . 2 . . 3 . .
//1 4 5 2 6 7 3 8 9
void solve() {
    int n; cin>>n;
    vector<int> head(n),tail(2*n);
    for(int i=0; i<n; ++i) {
        head[i]=i+1;
    }
    for(int i=0; i<2*n; ++i) {
        tail[i]=n+i+1;
    }
    vector<int> a(3*n);
    for(int i=0; i<n; ++i) {
        a[3*i+0]=head[i];
        a[3*i+1]=tail[2*i+0];
        a[3*i+2]=tail[2*i+1];
    }
    for(int i=0; i<a.size(); ++i) cout<<a[i]<<' ';
    cout<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}