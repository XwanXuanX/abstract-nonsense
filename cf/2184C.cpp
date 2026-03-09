// Problem: C. Huge Pile
// Contest: Codeforces - Codeforces Round 1072 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2184/C
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

void solve() {
    int n,k; cin>>n>>k;
    unordered_map<int,int> dp;
    queue<int> que;
    dp[n]=0;
    que.push(n);
    if(n==k) {
        cout<<0<<'\n';
        return;
    }
    while(que.size()) {
        auto nod=que.front();
        que.pop();
        assert(dp.count(nod));
        int l=nod/2,r=nod/2;
        if(nod%2) {
            l++;
        }
        if(!dp.count(l)) {
            dp[l]=dp[nod]+1;
            que.push(l);
        }
        if(!dp.count(r)) {
            dp[r]=dp[nod]+1;
            que.push(r);
        }
        if(l==k) {
            cout<<dp[l]<<'\n';
            return;
        }
        if(r==k) {
            cout<<dp[r]<<'\n';
            return;
        }
    }
    cout<<-1<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}