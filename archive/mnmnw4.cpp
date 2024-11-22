#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, q, in; cin >> n >> q;
    map<int, set<int>> G; // make sure the children is sorted in ascending order
    for(int i = 2; i <= n; ++i) cin >> in, G[in].insert(i);
    vector<int> sequence;
    function<void(int node, int parent)> dfs;
    dfs=[&](int node, int parent){
        sequence.push_back(node);
        if(G[node].size() == 1 && G[node].count(parent))
            return;
        for(auto adj : G[node])
            if(adj != parent)
                dfs(adj, node);
    };
    vector<int> idx(n + 1, 0); // the index of any node in sequence
    vector<int> sz(n + 1, 0); // the subtree size
    function<int(int node, int parent)> subsize;
    subsize = [&](int node, int parent) -> int {
        if(G[node].size() == 1 && G[node].count(parent))
            return sz[node] = 1;
        int sum = 1;
        for(auto adj : G[node])
            if(adj != parent)
                sum += subsize(adj, node);
        return sz[node] = sum;
    };
    dfs(1, -1); subsize(1, -1);
    for(int i = 0; i < sequence.size(); ++i) idx[sequence[i]] = i;
    int u, k;
    for(int i = 0; i < q; ++i){
        cin >> u >> k;
        if(k > sz[u]) cout << -1 << endl;
        else cout << sequence[idx[u] + k - 1] << endl;;
    }
}

/**
 * it can be seen that any subtree query is a subarray of the query start from node 1
 * we need to know the size of the subtree and the overall sequence, then we can answer any query in log(n) time
 */