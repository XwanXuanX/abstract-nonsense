/**
 * since we want to maximize a+b, then there should be at most one empty node in the tree
 * remove each node and it's edges, then count the number of nodes in both connected components
 * 5000 * 5000 = TLE
 */

// this shit does not WORK!!!!!!!!!!!!!!

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,u,v;
    cin>>n;
    map<int,vector<int>> G;
    for(int i=0;i<n-1;++i){
        cin>>u>>v;
        G[u].push_back(v), G[v].push_back(u);
    }
    set<pair<int,int>> ans;
    int start=0;
    // when you start dfs, you need to start from a leaf node (any leaf node)
    for(int i=1;i<=n;++i)
        if(G[i].size()==1){
            start=i;
            break;
        }
    // for each subtree, we record the answer by minus the # of nodes in the subtree from the total number of nodes
    function<int(int node, int parent)> dfs;
    dfs=[&](int node, int parent)->int{
        if(G[node].size()==1 && G[node][0]==parent){ // it's a leaf node, and leaf node cannot be empty junction
            return 1;
        }
        int subtree=0;
        for(auto adj:G[node]){
            if(adj==parent)
                continue;
            subtree+=dfs(adj, node);
        }
        // if the node is the root, can not be empty
        if(node!=start)
            ans.insert(make_pair(subtree, n-subtree-1)), \
            ans.insert(make_pair(n-subtree-1, subtree));
        return subtree+1;
    };
    dfs(start,-1);
    cout<<ans.size()<<endl;
    for(auto& p:ans) cout<<p.first<<' '<<p.second<<endl;
    return 0;
}