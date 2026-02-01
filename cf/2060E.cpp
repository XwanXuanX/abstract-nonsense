// Problem: E. Graph Composition
// Contest: Codeforces - Codeforces Round 998 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2060/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define double long double
constexpr int INF = 1ll<<60;
constexpr int MOD = 1000000007; // 998244353;
template<typename T> using MaxPQ = priority_queue<T,vector<T>,less<T>>;
template<typename T> using MinPQ = priority_queue<T,vector<T>,greater<T>>;
template<typename T> bool chmin(T& a,const T& b) {if(b<a){a=b;return true;}return false;}
template<typename T> bool chmax(T& a,const T& b) {if(b>a){a=b;return true;}return false;}

void solve() {
    int n,m1,m2; cin>>n>>m1>>m2;
    vector<unordered_set<int>> F(n+1),G(n+1);
    for(int i=0; i<m1; ++i) {
        int u,v; cin>>u>>v;
        F[u].insert(v), F[v].insert(u);
    }
    for(int i=0; i<m2; ++i) {
        int u,v; cin>>u>>v;
        G[u].insert(v), G[v].insert(u);
    }
    //partition G into connected components
    //then solve for individual component
    vector<int> vis(n+1,0);
    auto dfsG=[&](this auto&& dfs, unordered_set<int>& cc, int nd)->void {
        assert(vis[nd]);
        for(auto&& adj:G[nd]) {
            if(vis[adj]) continue;
            vis[adj]|=1, cc.insert(adj);
            dfs(cc,adj);
        }
    };
    int ans=0;
    for(int i=1; i<=n; ++i) {
        if(vis[i]) continue;
        unordered_set<int> cc={i};
        vis[i]|=1;
        dfsG(cc,i);
        // for(auto&& c:cc) cout<<c<<' '; cout<<'\n';
        //break connected component
        for(auto&& nd:cc) {
            unordered_set<int> nadj;
            vector<int> removed;
            for(auto&& adj:F[nd]) {
                if(cc.count(adj)) nadj.insert(adj);
                else removed.push_back(adj);
            }
            for(auto&& rem:removed) {
                F[rem].erase(nd);
            }
            ans+=F[nd].size()-nadj.size();
            F[nd]=std::move(nadj);
        }
        //reconnect componenets
        unordered_set<int> vis;
        auto dfsF=[&](this auto&& dfs, int nd)-> void {
            assert(!vis.count(nd));
            vis.insert(nd);
            for(auto&& adj:F[nd]) {
                if(vis.count(adj)) continue;
                dfs(adj);
            }
        };
        int cnt=0;
        for(auto&& c:cc) {
            if(vis.count(c)) continue;
            cnt++;
            dfsF(c);
        }
        ans+=cnt-1;
    }
    cout<<ans<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}