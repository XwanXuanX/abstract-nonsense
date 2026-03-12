// Problem: B. Abraham's Great Escape
// Contest: Codeforces - Codeforces Round 1056 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2155/B
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

//if a cell cannot escape, then there must be a loop
//create a loop, fill everything else with U, done
//RL
//UD
void solve() {
    int n,k; cin>>n>>k;
    int loop=n*n-k;
    if(loop==0) {
        cout<<"YES\n";
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                cout<<"U"; 
            }
            cout<<'\n';
        }
        return;
    }
    if(loop==1) {
        cout<<"NO\n";
        return;
    }
    //use RL pattern to trap, can handle any # >= 2
    vector<vector<char>> ans(n,vector<char>(n,'D'));
    int pop=loop/2, i=0, j=0;
    for(i=0; i<n; ++i) {
        for(j=0; j<n; j+=2) {
            if(pop==0 || j+1>=n) {
                break;
            }
            ans[i][j]='R', ans[i][j+1]='L';
            pop--;
        }
        if(pop==0) {
            break;
        }
    }
    int need=pop*2 + loop%2;
    debug(print(need);); // we still need pop*2 + loop%2 cells
    if(n%2) {
        for(int o=0; o<i && need>0; ++o) {
            ans[o][n-1]='L';
            need--;
        }
    }
    //2 cases:
    //1. if previous did not reach limit, then definitely 0 or 1 left
    //2. if previous reached limit, then either we are done, or need to fill the right -> done
    if(need>0) {
        debug(print(i,j););
        if(n%2) {
            ans[i][j]='L';
        } else {
            if(j>=n) ans[i+1][0]='U';
            else ans[i][j]='L';
        }
        need--;
    }
    cout<<"YES\n";
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cout<<ans[i][j];
        }
        cout<<'\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}