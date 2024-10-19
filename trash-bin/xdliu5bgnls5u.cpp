#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m,a,b;
    cin>>n>>m;
    map<int,set<int>> G;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        G[a].insert(b), G[b].insert(a);
    }
    // if we can divide the teams, then there must be exactly n/3 connected components
    vector<vector<int>> teams3, teams2;
    vector<int> team1;
    set<int> vis;
    function<void(int node, vector<int>& nodes)> dfs;
    dfs=[&](int node, vector<int>& nodes){
        vis.insert(node);
        nodes.push_back(node);
        for(auto adj:G[node]){
            if(vis.count(adj)) continue;
            dfs(adj,nodes);
        }
    };
    // classify teams based on group size
    for(int node=1;node<=n;++node){
        if(vis.count(node)) continue;
        vector<int> nodes;
        dfs(node, nodes);
        if(nodes.size()>3){
            cout<<-1<<endl;
            return 0;
        }
        if(nodes.size()==3) teams3.push_back(nodes);
        else if(nodes.size()==2) teams2.push_back(nodes);
        else team1.push_back(nodes.front());
    }
    // make 3-people team from 2-people team
    for(auto& t2:teams2){
        if(team1.size()==0){
            cout<<-1<<endl;
            return 0;
        }
        t2.push_back(team1.back()); team1.pop_back();
        teams3.push_back(t2);
    }
    // make 3-people team from 1-people team and this number must be a multiple of 3
    if(team1.size()%3!=0){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<team1.size();i+=3)
        teams3.push_back({team1[i],team1[i+1],team1[i+2]});
    for(auto& v:teams3){
        for(int i:v)
            cout<<i<<' ';
        cout<<endl;
    }
    return 0;
}

/**
 * if the size of any connected components is greater than 3, then no solution
 * otherwise it's always possible
 */