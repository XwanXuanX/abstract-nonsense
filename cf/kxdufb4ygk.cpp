#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,u,v;
    cin>>n;
    map<int,vector<int>> G;
    for(int i=0;i<n;++i){
        cin>>u>>v;
        G[u].push_back(v), G[v].push_back(u);
    }
    // we can dfs from any node (as the root), and we can guarentee to end up in a cycle
    set<int> stk, cyc;
    bool record=false;
    int meet=0;
    function<bool(int node, int parent)> dfs;
    dfs=[&](int node, int parent)->bool{
        if(stk.count(node)){
            record=true;
            meet=node;
            return true;
        }
        stk.insert(node);
        for(auto adj:G[node])
            if(adj!=parent && dfs(adj,node)){
                if(record)
                    cyc.insert(node);
                if(node==meet)
                    record=false;
                return true;
            }
        stk.erase(node);
        return false;
    };
    dfs(1,-1);
    // now we have all the nodes in the cycle, next we need to contense the cyclic component
    // we pick a representative, and connect all other subtrees of other nodes in the cyclic component
    // to that representative
    int rep=*cyc.begin();
    for(auto node:cyc){
        if(node==rep)
            continue;
        for(auto adj:G[node])
            if(!cyc.count(adj))
                G[rep].push_back(adj);
    }
    // now we do bfs from the rep node
    int path=0;
    deque<int> q;
    q.push_back(rep);
    cyc.erase(rep);
    vector<int> ans(n+1,0);
    while(q.size()){
        int sz=q.size();
        for(int k=0;k<sz;++k){
            int node=q.front(); q.pop_front();
            if(cyc.count(node))
                continue;
            cyc.insert(node);
            ans[node]=path;
            // push adjcent
            for(auto adj:G[node])
                if(!cyc.count(adj))
                    q.push_back(adj);
        }
        path++;
    }
    // print()
    for(int i=1;i<ans.size();++i)
        cout<<ans[i]<<' ';
    return 0;
}