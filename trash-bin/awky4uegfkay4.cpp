/**
 * if bottle a can open bottle b, there is an edge from a to b
 * the problem is a directed graph
 * if all bottles can be opened, there must exists at least one edge going into the node from another node
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,a,b;
    cin>>n;
    // count the number of bottles with brand a, each brand is a node
    map<int,int> cnt, cnt2;
    // all the brand b that brand bottle a can open
    map<int,set<int>> G;
    for(int i=0;i<n;++i){
        cin>>a>>b;
        cnt[a]++;
        if(a==b)
            cnt2[a]++;
        G[a].insert(b);
    }

    // now we need to find if each node has at least one in going edge
    map<int,int> indeg;
    for(auto& p:G){
        indeg[p.first];
        for(auto adj:p.second){
            indeg[adj]++;
        }
    }

    int ans=0;
    for(auto& p:indeg){
        if(p.second==0){
            ans+=cnt[p.first];
        }else if(p.second==1){
            if(cnt2[p.first]==1){
                ans++;
            }
            // if there are 2 self-loop, then no trouble
            // if there are 0 self-loop, no trouble, the indegree is constributed by others
        }
        // if the indegree is more than 1, then there is another way to open the bottle
    }

    cout<<ans<<endl;
    return 0;
}
