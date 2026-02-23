// Problem: D. Graph and Graph
// Contest: Codeforces - Codeforces Round 1002 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2059/D
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

//for ans to be finite, G1 and G2 should at least have a common edge
//also there must be a finite # of ops that takes s1 and s2 to any end point of a common edge
//work on the product graph, where each node is (a,b), a in g1 and b in g2
//run dijkstra on product graph, compute reachability and shortest paths from (s1,s2) to all other nodes
//then get all common edges of g1 and g2, check reachability to end points of all common edges
//done.
//
//note: why doing shortest path on the product graph also determines reachability?
//because assume that the answer exists. then there must be a sequence of operations that move
//along the edges of the product graph to the target node (a,b), and also true conversely.
//thus it's a iff condition. therefore doing shortest path finds the min number of operations (if ans exists),
//and determine reachability otherwise.
void solve() {
    int n,s1,s2; cin>>n>>s1>>s2;
    int m1; cin>>m1;
    vector<pair<int,int>> e1,e2;
    vector<vector<int>> g1(n+1),g2(n+1);
    for(int i=0; i<m1; ++i) {
        int a,b; cin>>a>>b;
        e1.push_back({a,b});
        g1[a].push_back(b), g1[b].push_back(a);
    }
    int m2; cin>>m2;
    for(int i=0; i<m2; ++i) {
        int a,b; cin>>a>>b;
        e2.push_back({a,b});
        g2[a].push_back(b), g2[b].push_back(a);
    }
    //dijkstra <cost, g1 node, g2 node>
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
    vector<vector<int>> dist(n+1,vector<int>(n+1,INF));
    dist[s1][s2]=0;
    pq.push({0,s1,s2});
    while(pq.size()) {
        auto[w,a,b]=pq.top();
        pq.pop();
        //skip stale entries
        if(w>dist[a][b]) {
            continue;
        }
        for(auto&& adj1:g1[a]) {
            for(auto&& adj2:g2[b]) { // new node=(adj1,adj2)
                int nw=abs(adj1-adj2);
                if(dist[a][b]+nw<dist[adj1][adj2]) {
                    dist[adj1][adj2]=dist[a][b]+nw;
                    pq.push({dist[adj1][adj2],adj1,adj2});
                }
            }
        }
    }
    for(auto& e:e1) {
        e={min(e.first,e.second),max(e.first,e.second)};
    }
    for(auto& e:e2) {
        e={min(e.first,e.second),max(e.first,e.second)};
    }
    vector<pair<int,int>> econ;
    for(auto&& a:e1) {
        for(auto& b:e2) {
            if(a==b) {
                econ.push_back(a);
            }
        }
    }
    int ans=INF;
    for(auto&& e:econ) {
        ans=min(ans,dist[e.first][e.first]);
        ans=min(ans,dist[e.second][e.second]);
    }
    cout<<(ans==INF?-1:ans)<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}