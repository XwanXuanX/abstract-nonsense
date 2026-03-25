// Problem: D. Rudolf and the Ball Game
// Contest: Codeforces - Codeforces Round 933 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1941/D
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
    int n,m,x; cin>>n>>m>>x;
    vector<pair<int,char>> turns;
    for(int i=0; i<m; ++i) {
        int d; char c; cin>>d>>c;
        turns.push_back({d,c});
    }
    auto pos=[&](int d,int i)->int {
        return (i+ (d%n) + n)%n;
    };
    vector<vector<int>> dp(m+1,vector<int>(n,0));
    dp[0][x-1]=1;
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            if(!dp[i][j]) continue;
            //we are processing throw i now
            auto[dist,dir]=turns[i];
            if(dir=='?') { //can be both
                int clock=pos(dist,j), counter=pos(-dist,j);
                dp[i+1][counter]=dp[i+1][clock]=1;
            } else if(dir=='0') { //clockwise
                int nj=pos(dist,j);
                dp[i+1][nj]=1;
            } else { //counter clockwise
                int nj=pos(-dist,j);
                dp[i+1][nj]=1;
            }
        }
    }
    vector<int> ans;
    for(int i=0; i<n; ++i) {
        if(dp[m][i]) ans.push_back(i+1);
    }
    cout<<ans.size()<<'\n';
    for(int i=0; i<ans.size(); ++i) {
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}