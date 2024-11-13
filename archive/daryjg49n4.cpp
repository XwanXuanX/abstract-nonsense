#include <bits/stdc++.h>
using namespace std;
#define int long long

// this is a graph question, two nodes can be connected iff the interval overlap
using inter=pair<int,int>;
// is there an edge from (p -> q)
bool can_connect(const inter& p, const inter& q){ // order does matter here!
    int a=q.first, b=q.second;
    return ((a<p.first && p.first<b) || (a<p.second && p.second<b));
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, a, b, c;
    cin>>n;
    map<int,set<int>> G; // empty graph initially
    vector<inter> nodes; // no nodes initially

    auto add=[&](const inter& nv){
        int idx=nodes.size();
        // add a node, compare with all other nodes in the graph and connect them
        for(int i=0;i<nodes.size();++i){
            if(can_connect(nv, nodes[i]))
                G[idx].insert(i);
            if(can_connect(nodes[i], nv))
                G[i].insert(idx);
        }
        // add the node to node list
        nodes.push_back(nv);
    };

    auto query=[&](int start, int end)->bool{
        set<int> vis;
        function<bool(int node)> dfs;
        dfs=[&](int node)->bool{
            if(node==end)
                return true;
            vis.insert(node);
            for(auto adj:G[node]){
                if(vis.count(adj))
                    continue;
                if(dfs(adj))
                    return true;
            }
            return false;
        };
        return dfs(start);
    };

    for(int i=0;i<n;++i){
        cin>>a>>b>>c;
        if(a==1){
            add(make_pair(b,c));
        }else{
            if(query(b-1, c-1))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }

    return 0;
}