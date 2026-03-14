// Problem: B. Yet Another MEX Problem
// Contest: Codeforces - Hello 2026
// URL: https://codeforces.com/problemset/problem/2183/B
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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

//0 1 2 1 0
//0 1 1 0 - 1
//0 1 0   - 2
//0 1     - 3
//the max mex you can achieve is min(MEX of a, k-1)
//can you construct a way to always achieve that?
//greedily, in the final array, we want 0...k-2, which only has k-1 number of elements
//therefore, in any window of size k, there are either k-1 or duplicate elements, which
//can be freely deleted without worsening the result. Thus if the MEX(a) >= K-1, you can always
//achieve K-1.
//on the other hand, since MEX is monotonic, if MEX(a) < K-1, you cannot make it better, thus your answer.
void solve() {
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    unordered_map<int,int> cnt;
    for(int i=0; i<n; ++i) {
        cnt[a[i]]++;
    }
    int mex=0;
    while(cnt[mex]) {
        mex++;
    }
    cout<<min(mex,k-1)<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}