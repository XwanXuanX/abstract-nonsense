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
        int n,m;
        cin>>n>>m;
        vector<vector<int>> G(n);
        for(int i=0; i<m; ++i) {
                int u,v;
                cin>>u>>v;
                u--,v--;
                G[u].push_back(v);
                G[v].push_back(u);
        }
        vector<int> color(n,-1);
        vector<pair<int,int>> cc;
        vector<int> which(n,-1);
        int cc_count=0;
        for(int i=0; i<n; ++i) {
                if(color[i]==-1) {
                        int black=0, white=0;
                        queue<pair<int,int>> que;
                        que.push({i,0});
                        white++;
                        color[i]=0;
                        which[i]=cc_count;
                        while(que.size()) {
                                auto[node,col]=que.front();
                                que.pop();
                                for(auto adj:G[node]) {
                                        if(color[adj]==!col) {
                                                continue;
                                        }
                                        if(color[adj]==col) {
                                                cout<<0<<'\n';
                                                return;
                                        } else if(color[adj]==-1) {
                                                color[adj]=!col;
                                        }
                                        que.push({adj,color[adj]});
                                        if(color[adj]==0) {
                                                white++;
                                        } else {
                                                black++;
                                        }
                                        which[adj]=cc_count;
                                }
                        }
                        cc.push_back({white,black});
                        cc_count++;
                }
        }
        //debug(print(color););
        int ans=0;
        int tot=0;
        for(int i=0; i<(int)cc.size(); ++i) {
                tot+=cc[i].first+cc[i].second;
        }
        for(int i=0; i<n; ++i) {
                if(color[i]==0) {
                        int con=0;
                        for(auto adj:G[i]) {
                                if(color[adj]==1) con++;
                        }
                        int self=cc[which[i]].second-con;
                        ans+=(tot-cc[which[i]].first-cc[which[i]].second)+self;
                } else {
                        int con=0;
                        for(auto adj:G[i]) {
                                if(color[adj]==0) con++;
                        }
                        int self=cc[which[i]].first-con;
                        ans+=(tot-cc[which[i]].first-cc[which[i]].second)+self;
                }
        }
        cout<<ans/2<<'\n';
}

signed main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int T=1; //cin>>T;
        while(T--) solve();
}
