// Problem: A. Concatenation of Arrays
// Contest: Codeforces - Codeforces Round 980 (Div. 1)
// URL: https://codeforces.com/problemset/problem/2023/A
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

/*
5 10 -> 4+8=12
// 2 3 -> 1+1
9 6 -> 7+5=12
// 4 1 -> 2+0
8 7 -> 6+6=12
2 3 4 1 5 10 9 6 8 7
*/
void solve() {
    int n; cin>>n;
    vector<vector<int>> a(n, vector<int>(2));
    for(int i=0; i<n; ++i) cin>>a[i][0]>>a[i][1];
    vector<int> inv(n,0);
    vector<int> SO;
    for(int i=0; i<n; ++i) {
        SO.push_back(a[i][0]), SO.push_back(a[i][1]);
    }
    sort(SO.begin(), SO.end());
    auto smaller=[&](const int x)->int {
        return lower_bound(SO.begin(),SO.end(),x) - SO.begin();
    };
    for(int i=0; i<n; ++i) {
        const int ff=a[i][0], ss=a[i][1];
        inv[i]=smaller(ff)+smaller(ss)-(ff!=ss ? 1:0);
    }
    // for(int i=0; i<n; ++i) cout<<inv[i]<<'\n';
    vector<pair<int,int>> ind(n);
    for(int i=0; i<n; ++i) {
        ind[i].first=inv[i], ind[i].second=i;
    }
    sort(ind.begin(), ind.end());
    vector<int> ans;
    for(int i=0; i<n; ++i) {
        const int p=ind[i].second;
        ans.push_back(a[p][0]), ans.push_back(a[p][1]);
    }
    for(int i=0; i<2*n; ++i) cout<<ans[i]<<' ';
    cout<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}