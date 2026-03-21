// Problem: D. Shift + Esc
// Contest: Codeforces - Codeforces Round 994 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2049/D
// Memory Limit: 512 MB
// Time Limit: 2500 ms
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

//each shift's penalty is k, only optimal if shift can reduce answer by at least k
//dp[i][j][o]=min cost to reach mat[i][j] when row i is shifted by 0<=o<=m-1
//mat[i][j] can be reached from mat[i-1][j] and mat[i][j-1]
//if same row, must have same shift amount, thus:
//    dp[i][j][o] = min(dp[i][j][o], dp[i][j-1][o] + shift(mat[i][j]))
//if from above row, row i-1 can have different shift amount, thus:
//    dp[i][j][o] = min(dp[i][j][o], for all k=0..m-1 dp[i-1][j][k] + shift(mat[i][j]))
void solve() {
    int n,m,k; cin>>n>>m>>k;
    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin>>mat[i][j];
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,INF)));
    auto sft=[&](int j, int s)->int {
        return (j+s)%m;
    };
    for(int o=0; o<m; ++o) {
        dp[0][0][o]=mat[0][sft(0,o)] + k*o;
        for(int j=1; j<m; ++j) {
            dp[0][j][o]=dp[0][j-1][o]+mat[0][sft(j,o)];
        }
    }
    for(int i=1; i<n; ++i) {
        for(int o=0; o<m; ++o) {
            int mn=INF;
            for(int l=0; l<m; ++l) { //from above
                mn=min(mn,dp[i-1][0][l]);
            }
            dp[i][0][o]=mn + mat[i][sft(0,o)] + k*o;
        }
    }
    for(int i=1; i<n; ++i) {
        for(int o=0; o<m; ++o) {
            for(int j=1; j<m; ++j) {
                //same row
                dp[i][j][o]=min(dp[i][j][o], dp[i][j-1][o] + mat[i][sft(j,o)]);
                //previous row
                int mn=INF;
                for(int l=0; l<m; ++l) {
                    mn=min(mn,dp[i-1][j][l]);
                }
                dp[i][j][o]=min(dp[i][j][o], mn + mat[i][sft(j,o)] + k*o);
            }
        }
    }
    int ans=INF;
    for(int o=0; o<m; ++o) {
        ans=min(ans,dp[n-1][m-1][o]);
    }
    cout<<ans<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}