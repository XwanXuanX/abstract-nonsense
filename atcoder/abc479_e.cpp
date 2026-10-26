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
        int n;
        cin>>n;
        vector<vector<pair<int,int>>> G(n);
        for(int i=0; i<n-1; ++i) {
                int u,v;
                cin>>u>>v;
                u--,v--;
                G[u].push_back({v,i+1});
                G[v].push_back({u,i+1});
        }
        //calc subtree size
        vector<int> sub(n,0);
        auto dfs=[&](auto&& self,int node,int par)->int{
                if(G[node].size()==1&&G[node][0].first==par) {
                        return sub[node]=1;
                }
                int acc=0;
                for(auto adj:G[node]) {
                        if(adj.first==par){
                                continue;
                        }
                        acc+=self(self,adj.first,node);
                }
                return sub[node]=acc+1;
        };
        dfs(dfs,0,-1);
        vector<int> diff(n,0);
        //do the edge thing in post order
        auto dfs2=[&](auto&& self,int node,int par)->void{
                //there is nothing to do for a leaf
                if(G[node].size()==1&&G[node][0].first==par) {
                        return;
                }
                //fan out
                for(auto adj:G[node]) {
                        if(adj.first!=par) {
                                self(self,adj.first,node);
                        }
                }
                //resolve each edge from the node
                for(auto adj:G[node]) {
                        if(adj.first==par) {
                                continue;
                        }
                        //two cases:
                        if(sub[adj.first]>n/2) {
                                //simply update the subtree
                                diff[adj.first]+=adj.second;
                        } else {
                                //update the entire tree then subtract the subtree to complement
                                diff[adj.first]-=adj.second;
                                diff[0]+=adj.second;
                        }
                }
        };
        dfs2(dfs2,0,-1);
        //propogate the result from root to leaf
        auto dfs3=[&](auto&& self,int node,int par)->void{
                //process self first using diff[par]
                //diff[par] must have been finalized
                diff[node]+=diff[par];
                for(auto adj:G[node]){
                        if(adj.first==par) {
                                continue;
                        }
                        self(self,adj.first,node);
                }
        };
        for(auto adj:G[0]) {
                dfs3(dfs3,adj.first,0);
        }
        for(int i=0; i<n; ++i) {
                cout<<diff[i]<<' ';
        }
        cout<<'\n';
}

signed main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int T=1; //cin>>T;
        while(T--) solve();
}
