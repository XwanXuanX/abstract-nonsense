// Problem: C. Non-Descending Arrays
// Contest: Codeforces - Educational Codeforces Round 182 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/2144/C
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
#define MOD 998244353

#ifndef ONLINE_JUDGE
    #include "debug.hpp"
    #define debug(...) do { __VA_ARGS__ } while (0)
#else
    #define debug(...) do {} while (0)
#endif

//1 1 3 5 6
//2 3 3 4 4
//2 3 | 3 | 5 6
//1 1 | 3 | 4 4
void solve() {
    int n; cin>>n;
    vector<int> a(n),b(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    for(int i=0; i<n; ++i) cin>>b[i];
    vector<vector<int>> one(n, vector<int>(2,0));
    //since there is one subset, then assign the first randomly
    one[0][0]=a[0], one[0][1]=b[0];
    for(int i=1; i<n; ++i) {
        int ai=a[i], bi=b[i];
        if(ai>=one[i-1][0] && bi>=one[i-1][1]) {
            one[i][0]=ai;
            one[i][1]=bi;
        } else {
            assert(bi>=one[i-1][0] && ai>=one[i-1][1]);
            one[i][1]=ai;
            one[i][0]=bi;
        }
    }
    // debug(print(one);); // seems about right
    int ans=1;
    //now the range swap must be a contiguous subarray
    //count the number of subarray that's independent
    vector<pair<int,int>> seg;
    int start=0;
    for(int i=1; i<n; ++i) {
        if(max(one[i-1][0],one[i-1][1])<=min(one[i][0],one[i][1])) {
            seg.push_back({start,i-1});
            start=i;
        }
    }
    seg.push_back({start,n-1});
    // debug(print(seg.size()););
    for(int i=0; i<seg.size(); ++i) {
        ans=((ans%MOD)*(2%MOD))%MOD;
    }
    cout<<ans<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}