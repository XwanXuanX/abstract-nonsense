// Problem: G. XOUR
// Contest: Codeforces - Codeforces Round 944 (Div. 4)
// URL: https://codeforces.com/contest/1971/problem/G
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
a^b < 4 <-> a^b at most 00000...0011
thus a b must be equal in the upper bits, and only differ in the lower 2
*/
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    map<int,vector<int>> cat, ind;
    for(int i=0; i<n; ++i) {
        int mask=(1l<<32)-1;
        mask^=1ll, mask^=(1<<1ll);
        int masked=a[i]&mask;
        cat[masked].push_back(a[i]);
        ind[masked].push_back(i);
    }
    for(auto&& p:cat) {
        sort(p.second.begin(), p.second.end());
    }
    for(auto&& p:cat) {
        auto& is=ind[p.first];
        assert(p.second.size()==is.size());
        for(int i=0; i<is.size(); ++i) {
            a[is[i]]=p.second[i];
        }
    }
    for(int i=0; i<n; ++i) cout<<a[i]<<' ';
    cout<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}