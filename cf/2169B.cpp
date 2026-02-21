// Problem: B. Drifting Away
// Contest: Codeforces - Educational Codeforces Round 184 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/2169/B
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

#ifndef ONLINE_JUDGE
    #include "debug.hpp"
    #define debug(...) do { __VA_ARGS__ } while (0)
#else
    #define debug(...) do {} while (0)
#endif

/*
** -> inf
>...< -> inf
>* or *< -> inf
*/
void solve() {
    string s; cin>>s;
    int n=s.size();
    for(int i=1; i<n; ++i) {
        if(s[i]=='*'&&s[i-1]=='*') {
            cout<<-1<<'\n';
            return;
        }
        if(s[i-1]=='>'&&s[i]=='*' || s[i-1]=='*'&&s[i]=='<') {
            cout<<-1<<'\n';
            return;
        }
    }
    int rt=0;
    for(int i=0; i<n; ++i) {
        if(s[i]=='>') {
            rt=1;
        } else if(s[i]=='<') {
            if(rt) {
                cout<<-1<<'\n';
                return;
            }
        }
    }
    //otherwise must be finite
    int ans1=0, ans2=0;
    for(int i=0; i<n; ++i) {
        if(s[i]=='<') {
            ans1++;
        }
    }
    for(int i=n-1; i>=0; --i) {
        if(s[i]=='>') {
            ans2++;
        }
    }
    int star=0;
    for(int i=0; i<n; ++i) {
        if(s[i]=='*') {
            star=1;
        }
    }
    cout<<max(ans1,ans2)+star<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}