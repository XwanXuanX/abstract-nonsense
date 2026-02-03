// Problem: E. Rudolf and k Bridges
// Contest: Codeforces - Codeforces Round 933 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1941/E
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

void solve() {
    int n,m,k,d; cin>>n>>m>>k>>d;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) cin>>a[i][j];
    }
    auto handle=[&](vector<int>& R)->int {
        vector<int> dp(m,INF);
        deque<int> dq;
        dp[0]=1;
        dq.push_back(0);
        for(int i=1; i<m; ++i) {
            while(dq.size() && dq.front()<max(i-d-1,0ll)) {
                dq.pop_front();
            }
            dp[i]=dp[dq.front()]+R[i]+1;
            while(dq.size() && dp[dq.back()]>=dp[i]) dq.pop_back();
            dq.push_back(i);
        }
        return dp[m-1];
    };
    vector<int> cost(n,0);
    for(int i=0; i<n; ++i) {
        cost[i]=handle(a[i]);
    }
    // debug(print(cost););
    for(int i=1; i<n; ++i) {
        cost[i]+=cost[i-1];
    }
    int ans=INF;
    cost.insert(cost.begin(),0ll);
    for(int i=1; i<=n-k+1; ++i) {
        int need=cost[i+k-1]-cost[i-1];
        ans=min(ans,need);
    }
    cout<<ans<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}