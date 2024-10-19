#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k,m,u,v;
    cin>>n>>k;
    map<int,set<int>> like, dislike;
    for(int i=0;i<k;++i){
        cin>>u>>v;
        like[u].insert(v), like[v].insert(u);
    }
    cin>>m;
    for(int i=0;i<m;++i){
        cin>>u>>v;
        dislike[u].insert(v), dislike[v].insert(u);
    }
    // we first need to enumerate all possible connected components from the like graph
    // then we need to check if this CC is viable. If is, we record the answer
    set<int> vis;
    function<void(int node, vector<int>& CC)> dfs;
    dfs=[&](int node, vector<int>& CC){
        vis.insert(node);
        CC.push_back(node);
        for(auto adj:like[node]){
            if(!vis.count(adj))
                dfs(adj, CC);
        }
    };
    // +++
    // check if this group of friends are viable
    auto ok=[&](vector<int>& CC)->bool{
        for(int i=0;i<CC.size();++i){
            for(int j=i+1;j<CC.size();++j){
                if(dislike[CC[i]].count(CC[j]))
                    return false;
            }
        }
        return true;
    };
    // +++
    int ans=0;
    for(int node=1;node<=n;++node){
        if(!vis.count(node)){
            vector<int> CC;
            dfs(node, CC);
            if(ok(CC))
                ans=max(ans,(int)CC.size());
        }
    }
    cout<<ans<<endl;
    return 0;
}