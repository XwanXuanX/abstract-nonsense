#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,t,e;
vector<int> obj;
vector<int> edges;
map<int,vector<int>> G, tG;

int ans=LLONG_MIN;
map<int,int> height, start;
int dfs(int node, int parent){
    if(G[node].size()==0){
        start[node]=node;
        return height[node]=1;
    }
    if(height.count(node))
        return height[node];
    int longest=LLONG_MIN;
    int st=0;
    for(auto adj:G[node])
        if(adj!=parent){
            int ht=dfs(adj,node);
            if(ht>longest){
                longest=ht;
                st=start[adj];
            }
        }
    start[node]=st;
    return height[node]=longest+1;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>t, obj.push_back(t);
    for(int i=0;i<n;++i)
        cin>>e, edges.push_back(e);
    // exclude the nodes with more than 1 out degree
    vector<int> deg(n+1,0);
    for(int i=0;i<edges.size();++i)
        deg[edges[i]]++;
    // if the nodes has two path leads from it, the node cannot be used as intermediate node
    // but it can be used as destination, but we know that hotel has outdegree of 0
    // so we won't accidentally remove hotels
    for(int i=0;i<edges.size();++i){
        if(edges[i]==0 || deg[edges[i]]>1)
            continue;
        int from=edges[i], to=i+1;
        G[to].push_back(from); // construct the transpose graph
        tG[from].push_back(to);
    }
    // find the height of each subtree
    int st=0;
    for(int i=0;i<obj.size();++i)
        if(obj[i]==1){
            int ht=dfs(i+1,-1);
            if(ht>ans){
                ans=ht;
                st=start[i+1];
            }
        }
    cout<<ans<<endl;
    // reconstruct the path
    vector<int> path;
    while(obj[st-1]!=1)
        path.push_back(st), st=tG[st].front();
    path.push_back(st);
    for(int i=0;i<path.size();++i)
        cout<<path[i]<<' ';
    return 0;
}