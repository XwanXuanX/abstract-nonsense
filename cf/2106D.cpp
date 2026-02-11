// Problem: D. Flower Boy
// Contest: Codeforces - Codeforces Round 1020 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2106/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int    long long
#define double long double
constexpr int INF = 1ll<<60;
constexpr int MOD = 1'000'000'007; // 998'244'353;
template<typename T> using MaxPQ = priority_queue<T,vector<T>,less<T>>;
template<typename T> using MinPQ = priority_queue<T,vector<T>,greater<T>>;
template<typename T> bool chmin(T& a,const T& b) {if (b<a) {a=b; return true;} return false;}
template<typename T> bool chmax(T& a,const T& b) {if (b>a) {a=b; return true;} return false;}

/*
k should be one of b[i]
by using k means making the b[i]th flower disappear and the rest is satisfied
use binary search on function check() that applies `magic` optimally
*/
void solve() {
    int n,m; cin>>n>>m;
    vector<int> a(n),b(m);
    for (int i=0; i<n; ++i) cin>>a[i];
    for (int i=0; i<m; ++i) cin>>b[i];
    auto check = [&](const int k)->bool {
        int dp0=0, dp1=-INF;
        auto insert=[&]() {
            chmax(dp1, dp0);
            if (dp0<m && k>=b[dp0]) {
                chmax(dp1, dp0+1);
            }
        };
        for (int i=0; i<n; ++i) {
            insert();
            if (dp0<m && a[i]>=b[dp0]) {
                dp0++;
            }
            if (dp1>(-INF)/2 && dp1<m && a[i]>=b[dp1]) {
                dp1++;
            }
        }
        insert();
        return dp0>=m || dp1>=m;
    };
    if (check(0)) {
        cout<<0<<'\n';
        return;
    }
    vector<int> c=b;
    sort(c.begin(),c.end());
    int l=0, r=c.size()-1, ans=INF;
    while (l<=r) {
        int mid=(l+r)>>1;
        if (check(c[mid])) {
            r=mid-1;
            chmin(ans,mid);
        } else {
            l=mid+1;
        }
    }
    cout<<(ans==INF?-1:c[ans])<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0), cin.exceptions(cin.failbit);
    int T = 1; cin >> T;
    while (T--) solve();
}