// Problem: B. Farmer John's Card Game
// Contest: Codeforces - Codeforces Round 998 (Div. 3)
// URL: https://codeforces.com/contest/2060/problem/B
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
    int n,m; cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j) cin>>a[i][j];
    for(int i=0; i<n; ++i) {
        sort(a[i].begin(), a[i].end());
    }
    vector<pair<int,int>> ind;
    for(int i=0; i<n; ++i) {
        ind.push_back({a[i][0],i});
    }
    sort(ind.begin(),ind.end()); // one candidate
    vector<int> fin;
    for(int i=0; i<ind.size(); ++i) {
        fin.push_back(ind[i].first);
    }
    for(int j=1; j<m; ++j) {
        for(auto&& p:ind) {
            fin.push_back(a[p.second][j]);
        }
    }
    // for(auto&& f:fin) cout<<f<<' '; cout<<'\n';
    if(!is_sorted(fin.begin(),fin.end())) {
        cout<<-1<<'\n';
        return;
    }
    for(int i=1; i<fin.size(); ++i) {
        if(fin[i]==fin[i-1]) {
            cout<<-1<<'\n';
            return;
        }
    }
    for(auto&& p:ind) {
        cout<<p.second+1<<' ';
    }
    cout<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}