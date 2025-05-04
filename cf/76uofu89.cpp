#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,u,v;
map<int,vector<int>> G;
int ans=0;

// return the number of nodes in each subtree
int dfs(int node, int parent){
    if(G[node].size()==1 && G[node][0]==parent) // leaf is definitly odd
        return 1;
    int sum=0;
    for(auto adj:G[node])
        if(adj!=parent)
            sum+=dfs(adj,node);
    if((sum+1)%2==0){ // you can make a cut above the parent node
        ans++;
        return 0;
    }
    return sum+1;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    // if number of nodes is odd initially, no way to make it even
    // otherwise there must be a way
    if(n%2!=0){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<n-1;++i){
        cin>>u>>v;
        G[u].push_back(v), G[v].push_back(u);
    }
    dfs(1,-1);
    cout<<ans-1<<endl;
    return 0;
}