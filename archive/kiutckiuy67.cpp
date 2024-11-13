#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,a,b;
    cin>>n>>m;
    map<int,set<int>> G;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        G[a].insert(b), G[b].insert(a);
    }

    function<int(int node, int parent, vector<int>& grp, int k)> dfs;
    dfs=[&](int node, int parent, vector<int>& grp, int k)->int{
        if(k == 1){ // the last node, check if it's connected to first node
            if(G[node].count(grp.front())){
                return G[grp[0]].size() + G[grp[1]].size() + G[node].size() - 6;
            }else{
                return LLONG_MAX;
            }
        }
        // not the last node, keep searching
        int res=LLONG_MAX;
        for(auto adj:G[node])
            if(adj != parent){
                grp.push_back(node);
                res=min(res, dfs(adj, node, grp, k-1));
                grp.pop_back();
            }
        return res;
    };

    int ans=LLONG_MAX;
    vector<int> grp;
    // for each of the node, check if it can be a part of the group
    for(int i=1;i<=n;++i)
        ans=min(ans, dfs(i, -1, grp, 3));

    cout << ((ans==LLONG_MAX) ? -1 : ans) << endl;
    return 0;
}

/**
 * in short, we need a cycle of 3 nodes to form the group
 * if a node is a canidate, then ans = # edges - 2 (which is the other two)
 */