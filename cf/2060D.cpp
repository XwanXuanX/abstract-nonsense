// Problem: D. Subtract Min Sort
// Contest: Codeforces - Codeforces Round 998 (Div. 3)
// URL: https://codeforces.com/contest/2060/problem/D
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

//4 5 2 3
//4 6 1 3 -> 0 2 1 3
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    for(int i=1; i<n; ++i) {
        if(a[i]<a[i-1]) {
            cout<<"NO\n";
            return;
        }
        int mn=min(a[i], a[i-1]);
        a[i]-=mn, a[i-1]-=mn;
    }
    cout<<"YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}