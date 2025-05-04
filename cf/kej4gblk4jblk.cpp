#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
    int n,u,v;
    cin>>n;
    map<int,vector<pair<int,int>>> G;
    vector<int> deg(n,0);
    for(int i=0;i<n-1;++i){
        cin>>u>>v;
        u--, v--;
        deg[u]++, deg[v]++;
        G[u].push_back(make_pair(v,i)), G[v].push_back(make_pair(u,i));
    }
    // if a node has more than 2 connected edges, then not possible
    int leaf=-1;
    for(int i=0;i<n;++i)
        if(deg[i]>2){
            cout<<-1<<endl;
            return;
        }else if(deg[i]==1 && leaf==-1){
            leaf=i;
        }
    // the tree is guarenteed to be a linked-list structure
    // you can start with any leaf node
    vector<int> weight(n-1,0);
    int w=2, cnt=0;
    auto getw=[&]()->int{
        if(w==2){
            w=3;
            return 2;
        }else{
            w=2;
            return 3;
        }
    };
    function<void(int node, int parent)> dfs;
    dfs=[&](int node, int parent){
        if(G[node].size()==1 && G[node][0].first==parent)
            return;
        for(auto adj:G[node])
            if(adj.first!=parent){
                weight[adj.second]=getw();
                dfs(adj.first, node);
            }
    };
    dfs(leaf,-1);
    for(int i=0;i<n-1;++i)
        cout<<weight[i]<<' ';
    cout<<endl;
    return;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}

/**
 * 2-1-3-4
 */