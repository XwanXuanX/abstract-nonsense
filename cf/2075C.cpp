// Problem: C. Two Colors
// Contest: Codeforces - Educational Codeforces Round 176 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/2075/C
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
a[i]<a[j]<a[k], and a[i]+a[j]>=n
find min# of planks can be painted with a[i], and max# of planks
([1,2,2,2,2], [1,1,2,2,2])*2
ub-lb1+1 + ub-lb2+1 + ub-lb3+1 + ... ub-lbm+1
= ub+ub+...+ub - (lb1+lb2+...+lbm) + 1+1+1+...+1
*/
void solve() {
    int n,m; cin>>n>>m;
    vector<int> a(m);
    for(int i=0; i<m; ++i) cin>>a[i];
    sort(a.begin(),a.end());
    vector<int> LB(m);
    for(int i=0; i<m; ++i) {
        LB[i]=max(n-a[i], 1ll);    
    }
    for(int i=1; i<m; ++i) {
        LB[i]+=LB[i-1];
    }
    int ans=0;
    for(int i=0; i<m-1; ++i) {
        // search for 1st a[j] st a[i]+a[j]>=n
        // -> a[j]>=n-a[i]
        int l=i+1, r=m-1, ind=m;
        while(l<=r) {
            const int mid=(l+r)>>1;
            if(a[mid]>=n-a[i]) {
                ind=min(ind, mid);
                r=mid-1;
            } else {
                l=mid+1;
            }
        }
        if(ind==m) continue;
        const int suff=LB[m-1]-LB[ind-1], dist=m-ind;
        const int ub=min(a[i], n-1);
        ans+=(ub*dist - suff + dist);
    }
    // for(int i=0; i<m; ++i) {
        // for (int j=i+1; j<m; ++j) {
            // if(a[i]+a[j]<n) continue;
            // const int lb=max(n-a[j], 1ll), ub=a[i];
            // assert(ub>=lb);
            // ans+=(ub-lb+1);
        // }
    // }
    cout<<ans*2<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}