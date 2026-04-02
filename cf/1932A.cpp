// Problem: A. Thorns and Coins
// Contest: Codeforces - Codeforces Round 927 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1932/A
// Memory Limit: 512 MB
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
    string s; cin>>s;
    vector<int> dp(n,0);
    for(int i=1; i<n; ++i) if(s[i]!='*') {
        int ok=(i-1>=0 && s[i-1]!='*') || (i-2>=0 && s[i-2]!='*');
        if(!ok) break;
        if(i-1>=0 && s[i-1]!='*') dp[i]=max(dp[i],dp[i-1]+(s[i]=='@'));
        if(i-2>=0 && s[i-2]!='*') dp[i]=max(dp[i],dp[i-2]+(s[i]=='@'));
    }
    cout<<*max_element(dp.begin(),dp.end())<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}