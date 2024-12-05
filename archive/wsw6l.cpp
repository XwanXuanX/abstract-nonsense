#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int n;
const int V = 26;
const int INF = 1e9;
vector<vector<int>> G(V, vector<int>(V, INF)); // directed

void floydWarshall(){
    for(int k=0; k<V; ++k)
        for(int i=0; i<V; ++i)
            for(int j=0; j<V; ++j)
                if(G[i][j] > (G[i][k] + G[k][j]) && (G[k][j] != INF && G[i][k] != INF))
                    G[i][j] = G[i][k] + G[k][j];
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>s1>>s2>>n;

    // initialize the distance vector
    for(int i=0; i<V; ++i)
        G[i][i] = 0;

    for(int i=0; i<n; ++i){
        char u, v; int w; cin>>u>>v>>w;
        u -= 'a'; v -= 'a';
        G[u][v] = min(G[u][v], w);
    }

    if(s1.size() != s2.size()){
        cout<<-1<<endl;
        return 0;
    }

    // precompute APSP
    floydWarshall();

    int ans=0;
    string res = s1;
    for(int i=0; i<s1.size(); ++i){
        if(s1[i] == s2[i]) continue;
        // need to check if s1[i] and s2[i] are in the same connected component
        // for two different chars, need to find a node w, such that cost(w,u) + cost(w,v) is minimum
        // to check this efficiently, we can compute all the shortest path from any node to u and v.
        // since there will only be 26 nodes, we can check all of them and pick the best
        // ops count = 1e5 * 26
        int u = s1[i]-'a', v = s2[i]-'a';
        int best=INF, besti=0;

        for(int node=0; node<V; ++node){
            int dist = G[u][node] + G[v][node];
            if(dist < best){
                best = min(best, dist);
                besti = node;
            }
        }

        if(best == INF){
            cout<<-1<<endl;
            return 0;
        }

        ans += best;
        res[i] = (char)(besti + 'a');
    }

    cout<<ans<<endl<<res<<endl;
    return 0;
}