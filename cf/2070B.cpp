// Problem: B. Robot Program
// Contest: Codeforces - Educational Codeforces Round 175 (Rated for Div. 2)
// URL: https://codeforces.com/contest/2070/problem/B
// Memory Limit: 512 MB
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
    int n,x,k; cin>>n>>x>>k;
    string s; cin>>s;
    int reach=-1;
    for(int i=0; i<n; ++i) {
        if(s[i]=='L') x--; else x++;
        if(x==0) {
            reach=i+1;
            break;
        }
    }
    if(reach==-1) {
        cout<<0<<'\n';
        return;
    }
    int time=-1;
    for(int i=0; i<n; ++i) {
        if(s[i]=='L') x--; else x++;
        if(x==0) {
            time=i+1;
            break;
        }
    }
    if(time==-1) {
        cout<<1<<'\n';
        return;
    }
    cout<<(k-reach)/time+1<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}