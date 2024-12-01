#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj; // adjacency list - vertex and edge pairs
vector<pair<int, int>> edges;

vector<int> tin, low;
int bridge_cnt = 0;
string orient;
vector<bool> edge_used;
vector<pair<int,int>> ans;
void find_bridges(int v) {
    static int time = 0;
    low[v] = tin[v] = time++;
    for (auto p : adj[v]) {
        if (edge_used[p.second]) continue;
        edge_used[p.second] = true;
        if(v == edges[p.second].first){
            ans.push_back(make_pair(edges[p.second].first, edges[p.second].second));
        }else{
            ans.push_back(make_pair(edges[p.second].second, edges[p.second].first));
        }
        int nv = p.first;
        if (tin[nv] == -1) { // if nv is not visited yet
            find_bridges(nv);
            low[v] = min(low[v], low[nv]);
            if (low[nv] > tin[v]) {
                // a bridge between v and nv
                bridge_cnt++;
            }
        } else {
            low[v] = min(low[v], low[nv]);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    adj.resize(n);
    tin.resize(n, -1);
    low.resize(n, -1);
    orient.resize(m);
    edges.resize(m);
    edge_used.resize(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
        edges[i] = {a, b};
    }
    find_bridges(0);
    if(bridge_cnt > 0){
        printf("%d\n", 0);
        return 0;
    }
    for(auto& p:ans)
        printf("%d %d\n", p.first+1, p.second+1);
    return 0;
}