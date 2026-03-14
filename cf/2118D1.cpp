// Problem: D1. Red Light, Green Light (Easy version)
// Contest: Codeforces - Codeforces Round 1030 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2118/D1
// Memory Limit: 512 MB
// Time Limit: 4000 ms
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

//formulate the problem as a graph
//each light is a node
//there is an edge from L1 to L2 if at the time when L1 is red and direction changed,
//and you continue walking, you will need to turn around again at L2.
//this works because when you stop, the light must be RED, which matches the definition of the edge
void solve() {
    int n,k; cin>>n>>k;
    vector<int> p(n),d(n);
    for(int i=0; i<n; ++i) cin>>p[i];
    for(int i=0; i<n; ++i) cin>>d[i];
    auto handle_pos=[&](int ind)->int { //search in pos direction
        for(int i=ind+1; i<n; ++i) {
            int time=p[i]-p[ind], delta=d[i]-d[ind];
            if((time-delta)%k==0) {
                return i;
            }
        }
        return INF;
    };
    auto handle_neg=[&](int ind)->int { //search in neg direction
        for(int i=ind-1; i>=0; --i) {
            int time=p[ind]-p[i], delta=d[i]-d[ind];
            if((time-delta)%k==0) {
                return i;
            }
        }
        return -1;
    };
    //there must be two color for edges, POS and NEG
    vector<vector<pair<int,int>>> g(n);
    for(int i=0; i<n; ++i) {
        int pos=handle_pos(i), neg=handle_neg(i);
        g[i].push_back({pos,1}), g[i].push_back({neg,0});
    }
    // debug(print(g);); //seems about right
    //for all states, traverse the graph to see if leads to INF or -1
    //each node can be visited at most twice, from neg and from pos
    vector<int> ans(n,0);
    auto handle=[&](int ind)->int {
        vector<vector<int>> vis(n,vector<int>(2,0));
        queue<pair<int,int>> que;
        que.push({ind,0});
        //you visited ind from neg side
        vis[ind][0]|=1;
        while(que.size()) {
            auto[node,dir]=que.front();
            que.pop();
            for(auto&& p:g[node]) {
                if(p.second!=dir) continue;
                if(p.first==-1 || p.first==INF) return true;
                //you will visit p.first from !dir side
                //found a cycle, abort
                if(vis[p.first][!dir]) return false;
                vis[p.first][!dir]|=1;
                que.push({p.first,!dir});
            }
        }
        return false;
    };
    for(int i=0; i<n; ++i) {
        ans[i]=handle(i);
    }
    int q; cin>>q;
    while(q--) {
        int a; cin>>a;
        //find which RED light will I encounter first
        int meet=-1;
        for(int i=0; i<n; ++i) {
            if(p[i]<a) continue;
            int time=p[i]-a, delta=d[i];
            if((time-delta)%k==0) {
                meet=i;
                break;
            }
        }
        if(meet==-1) {
            cout<<"YES\n";
            continue;
        }
        if(ans[meet]) cout<<"YES\n"; else cout<<"NO\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}