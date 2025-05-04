#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,u,v;
    cin>>n;
    map<int,vector<int>> G;
    vector<int> c(n);
    for(int i=0;i<n-1;++i){
        cin>>u>>v; u--, v--;
        G[u].push_back(v), G[v].push_back(u);
    }
    for(int i=0;i<n;++i)
        cin>>c[i];

    vector<int> diff(n);
    for(int i=0;i<n;++i)
        for(auto adj:G[i])
            if(c[i] != c[adj])
                diff[i]++;
    
    bool found=false;
    int root=0;
    for(int i=0;i<n;++i)
        if(diff[i] > 1){
            if(found){
                cout<<"NO"<<endl;
                return 0;
            }
            found=true;
            root=i;
        }
    
    function<bool(int node, int parent, int color)> dfs;
    dfs=[&](int node, int parent, int color)->bool{
        if(G[node].size()==1 && G[node][0]==parent)
            return c[node] == color;
        bool res=true;
        for(auto adj:G[node])
            if(adj != parent)
                res &= dfs(adj,node,color);
        res &= (c[node] == color);
        return res;
    };

    // otherwise, root has to be the node with diff > 1
    // but we need to be certain, do a dfs to check
    if(found){
        for(auto adj:G[root])
            if(!dfs(adj,root,c[adj])){
                cout<<"NO"<<endl;
                return 0;
            }
        cout<<"YES"<<endl<<root+1<<endl;
        return 0;
    }

    // when diff at most one, means pairwise different
    // there cannot be more than one pair of pairwise different nodes
    int count=0;
    for(int i=0;i<n;++i)
        if(diff[i] == 1)
            count++, root=i;
    
    if(count/2 > 1){
        cout<<"NO"<<endl;
        return 0;
    }

    // definitly ok, since at most one pair different
    cout<<"YES"<<endl;
    if(count) cout<<root+1<<endl;
    else  cout<<1<<endl;

    return 0;
}

/**
 * the color of the root is not important, but its adjcent nodes are important
 */