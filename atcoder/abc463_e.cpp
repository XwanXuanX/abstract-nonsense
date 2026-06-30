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

vector<int> dijkstra(int s, vector<vector<pair<int,int>>>& g) {
        int N = g.size();
        vector<int> dist(N, INF);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[s] = 0;
        pq.push({0, s});
        while(!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
                if(d != dist[u]) continue;
                for(auto [v, w] : g[u]) {
                        if(dist[v] > d + w) {
                                dist[v] = d + w;
                                pq.push({dist[v], v});
                        }
                }
        }
        return dist;
}

void solve() {
        int n,m,y;
        cin>>n>>m>>y;
        vector<vector<pair<int,int>>> g(n+1);
        for(int i=0; i<m; ++i) {
                int u,v,t;
                cin>>u>>v>>t;
                u--, v--;
                g[u].push_back({v,t}), g[v].push_back({u,t});
        }
        vector<int> x(n);
        for(int i=0; i<n; ++i) {
                cin>>x[i];
        }
        for(int i=0; i<n; ++i) {
                g[i].push_back({n,x[i]}); // entering
                g[n].push_back({i,x[i]+y}); // quitting
        }
        auto ans=dijkstra(0, g);
        for(int i=1; i<n; ++i) {
                cout<<ans[i]<<' ';
        }
        cout<<'\n';
        return;
}

signed main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int T=1; //cin>>T;
        while(T--) solve();
}
