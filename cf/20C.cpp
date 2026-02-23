// Problem: C. Dijkstra?
// Contest: Codeforces - Codeforces Alpha Round 20 (Codeforces format)
// URL: https://codeforces.com/problemset/problem/20/C
// Memory Limit: 64 MB
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
    int n,m; cin>>n>>m;
    vector<vector<pair<int,int>>> g(n+1);
    for(int i=0; i<m; ++i) {
        int a,b,w; cin>>a>>b>>w;
        g[a].push_back({b,w}),g[b].push_back({a,w});
    }
    vector<int> dist(n+1,INF), par(n+1,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[1]=0;
    pq.push({0,1});
    while(pq.size()) {
        auto[d,a]=pq.top();
        pq.pop();
        if(d>dist[a]) {
            continue;
        }
        for(auto&& [b,w]:g[a]) {
            if(d+w<dist[b]) {
                par[b]=a;
                dist[b]=d+w;
                pq.push({dist[b],b});
            }
        }
    }
    if(dist[n]==INF) {
        assert(par[n]==0);
        cout<<-1<<'\n';
        return;
    }
    int cur=n;
    vector<int> path={n};
    while(par[cur]!=0) {
        path.push_back(par[cur]);
        cur=par[cur];
    }
    reverse(path.begin(),path.end());
    for(int i=0; i<path.size(); ++i) {
        cout<<path[i]<<' ';
    }
    cout<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1;
    while(T--) solve();
}