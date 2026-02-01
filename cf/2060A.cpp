// Problem: A. Fibonacciness
// Contest: Codeforces - Codeforces Round 998 (Div. 3)
// URL: https://codeforces.com/contest/2060/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
    int a1,a2,a4,a5;
    cin>>a1>>a2>>a4>>a5;
    auto ck=[&](int a3)->int {
        int sum=0;
        vector<int> b={a1,a2,a3,a4,a5};
        for(int i=2; i<5; ++i) {
            if(b[i]==b[i-1]+b[i-2]) sum++;
        }
        return sum;
    };
    int ans=0;
    for(int a3=-1000; a3<=1000; ++a3) {
        ans=max(ans,ck(a3));
    }
    cout<<ans<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}