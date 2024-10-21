#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,x,y,t;
    cin>>n;
    map<int,vector<pair<int,bool>>> G;
    for(int i=0;i<n-1;++i){
        cin>>x>>y>>t;
        G[x].push_back(make_pair(y,(t==1)?false:true)), G[y].push_back(make_pair(x,(t==1)?false:true));
    }
    /**
     * we only include the terminal node
     * if we found a terminal node on a path, report upward
     */
    set<int> ans, vis;
    function<bool(int node, int parent, bool rep)> dfs;
    dfs=[&](int node, int parent, bool rep)->bool{
        vis.insert(node);
        if(G[node].size()==1 && G[node][0].first==parent){
            if(rep){
                ans.insert(node);
                return true;
            }
            return false;
        }
        bool has_term=false;
        for(auto& adj:G[node]){
            if(vis.count(adj.first))
                continue;
            bool res=dfs(adj.first, node, adj.second);
            has_term |= res;
        }
        if(!has_term && rep){
            ans.insert(node);
            return true;
        }
        return has_term;
    };
    dfs(1, -1, false);
    cout<<ans.size()<<endl;
    for(auto i:ans) cout<<i<<' ';
    return 0;
}