// Problem: B. Impost or Sus
// Contest: Codeforces - Good Bye 2025
// URL: https://codeforces.com/problemset/problem/2178/B
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

//uuuuuuuuuuu
//sususususus
void solve() {
    string s; cin>>s;
    int n=s.size();
    int ans=0;
    if(s[0]=='u') {
        s[0]='s';
        ans++;
    }
    if(s[n-1]=='u') {
        s[n-1]='s';
        ans++;
    }
    int start=0;
    vector<pair<int,int>> seg;
    for(int i=1; i<n; ++i) {
        if(s[i]!=s[i-1]) {
            seg.push_back({start,i-1});
            start=i;
        }
    }
    seg.push_back({start,n-1});
    for(auto[i,j]:seg) {
        assert(s[i]==s[j]);
        if(s[i]=='s') continue;
        int len=j-i+1;
        ans+=len/2;
    }
    cout<<ans<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}