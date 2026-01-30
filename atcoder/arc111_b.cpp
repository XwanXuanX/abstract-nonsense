// Problem: B - Reversible Cards
// Contest: AtCoder - AtCoder Regular Contest 111
// URL: https://atcoder.jp/contests/arc111/tasks/arc111_b
// Memory Limit: 1024 MB
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

struct safe_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
template <class K, class V> using safe_map = unordered_map<K, V, safe_hash>;
template <class T> using safe_set = unordered_set<T, safe_hash>;

void solve() {
    int n; cin>>n;
    safe_map<int,vector<int>> G;
    for(int i=0; i<n; ++i) {
        int a,b; cin>>a>>b;
        G[a].push_back(b), G[b].push_back(a);
    }
    safe_set<int> vis;
    auto dfs=[&](this auto&& dfs, int nod, int& E, int& V)->void {
        assert(!vis.count(nod));
        vis.insert(nod);
        V++, E+=(int)G[nod].size();
        for(const auto& adj : G[nod]) {
            if(vis.count(adj)) continue;
            dfs(adj, E, V);
        }
    };
    int ans=0;
    for(const auto& p : G) {
        if(vis.count(p.first)) continue;
        int E=0, V=0;
        dfs(p.first, E, V);
        E/=2;
        if(E==V-1) ans+=V-1;
        else ans+=V;
    }
    cout<<ans<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; // cin>>T;
    while(T--) solve();
}