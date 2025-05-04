#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int INF = 1000000000;

// This solution gives TLE on the 26th testcase
// V + ElogV = 1e5 + 2e5 * 16 = 3e6 something

int n,m,u,v,w;
map<int,vector<pair<int,int>>> G;

void dijkstra(int s,vector<int>& d, vector<int>& p){
    vector<bool> uu(n+1, false); // store if the vertex has been visited
    d[s]=0;
    for (int i=0;i<n;i++){
        int v=-1;
        for(int j=0;j<n;j++) {
            if (!uu[j] && (v==-1 || d[j]<d[v]))
                v=j;
        }
        if(d[v]==INF)
            break;
        uu[v]=true;
        for (auto edge:G[v]) {
            int to=edge.first;
            int len=edge.second;
            if (d[v]+len<d[to]) {
                d[to]=d[v]+len;
                p[to]=v;
            }
        }
    }
}

vector<int> restore_path(int s, int t, vector<int> const& p){
    vector<int> path;
    for (int v = t; v != s; v = p[v])
        path.push_back(v);
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>u>>v>>w;
        u--, v--;
        G[u].push_back(make_pair(v,w)), G[v].push_back(make_pair(u,w));
    }
    vector<int> d(n,INF),p(n,-1);
    dijkstra(0,d,p);
    // if the target node is not connected to the source, then it's distance is INF
    if(d[n-1]==INF){
        cout<<-1<<endl;
        return 0;
    }
    vector<int> path=restore_path(0,n-1,p);
    for(int i=0;i<path.size();++i)
        cout<<path[i]+1<<' ';
    return 0;
}
