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

vector<long long> dijkstra_array(int src, vector<vector<long long>>& cost) {
    int n = cost.size();
    vector<long long> dist(n, INF);
    vector<bool> used(n, false);
    dist[src] = 0;
    for (int it = 0; it < n; ++it) {
        int v = -1;
        for (int i = 0; i < n; ++i) {
            if (!used[i] && (v == -1 || dist[i] < dist[v])) {
                v = i;
            }
        }
        if (dist[v] == INF) break;
        used[v] = true;
        // Relax all possible neighbors
        for (int u = 0; u < n; ++u) {
            if (cost[v][u] == INF) continue;
            dist[u] = min(dist[u], dist[v] + cost[v][u]);
        }
    }
    return dist;
}

void solve() {
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    vector<vector<int>> d(n,vector<int>(n));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cin >> d[i][j];
        }
    }
    vector<vector<int>> car = d;
    vector<vector<int>> train = d;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            car[i][j] *= a;
            train[i][j] = train[i][j]*b + c;
        }
    }
    vector<int> car_c = dijkstra_array(0, car);
    vector<int> train_c = dijkstra_array(n-1, train);
    int ans=INF;
    for(int i=0; i<n; ++i) {
        ans=min(ans, car_c[i]+train_c[i]);
    }
    ans=min(ans, car_c[n-1]);
    ans=min(ans, train_c[0]);
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T=1; //cin>>T;
    while(T--) solve();
}
