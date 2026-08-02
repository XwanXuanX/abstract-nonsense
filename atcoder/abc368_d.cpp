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
        int n,k;
        cin>>n>>k;
        vector<vector<int>> g(n);
        for(int i=0; i<n-1; ++i) {
                int u,v;
                cin>>u>>v;
                u--,v--;
                g[u].push_back(v),g[v].push_back(u);
        }
        set<int> V;
        for(int i=0; i<k; ++i) {
                int u;
                cin>>u;
                u--;
                V.insert(u);
        }
        vector<int> deg(n,0);
        for(int i=0; i<n; ++i) {
                for(auto adj:g[i]) {
                        deg[adj]++;
                }
        }
        queue<int> que;
        for(int i=0; i<n; ++i) {
                if(deg[i]==1) {
                        que.push(i);
                }
        }
        int rmed=0;
        while(que.size()) {
                int nod=que.front();
                que.pop();
                if(V.count(nod)) {
                        continue;
                }
                rmed++;
                for(auto adj:g[nod]) {
                        deg[adj]--;
                        if(deg[adj]==1) {
                                que.push(adj);
                        }
                }
        }
        cout<<n-rmed<<'\n';
}

signed main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int T=1; //cin>>T;
        while(T--) solve();
}
