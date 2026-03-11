// Problem: C. First or Second
// Contest: Codeforces - Good Bye 2025
// URL: https://codeforces.com/problemset/problem/2178/C
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

//-2 -3 4 10 -9
//after n-1 operations, exactly one will remain, so we can make n queries
//the people after the remaining must all be second, people before can be deleted in many ways
//problem: what is the max you can obtain from the prefix -> easy
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    vector<int> pfs(a.begin(),a.end());
    for(int i=1; i<n; ++i) {
        pfs[i]+=pfs[i-1];
    }
    vector<int> mx(n,0);
    mx[0]=a[0];
    for(int i=1; i<n; ++i) {
        mx[i]=mx[i-1]+abs(a[i]);
    }
    int ans=-INF;
    for(int i=0; i<n; ++i) {
        ans=max(ans,-(pfs[n-1]-pfs[i])+(i>0?mx[i-1]:0));
    }
    cout<<ans<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}