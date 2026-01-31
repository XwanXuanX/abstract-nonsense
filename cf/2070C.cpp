// Problem: C. Limited Repainting
// Contest: Codeforces - Educational Codeforces Round 175 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/2070/C
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
    int n,k; cin>>n>>k;
    string s; cin>>s;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    auto ok=[&](const int tol)->bool {
        int st=-1;
        for(int i=0; i<n; ++i) {
            if(s[i]=='B') {
                st=i;
                break;
            }
        }
        if(st==-1) return true;
        int paint=0, ing=a[st]>tol;
        for(int i=st+1; i<n; ++i) {
            if(ing) {
                if(s[i]=='R' && a[i]>tol) {
                    paint++, ing=false;
                }
            } else {
                if(s[i]=='B' && a[i]>tol) {
                    ing=true;
                }
            }
        }
        if(ing) paint++;
        return paint<=k;
    };
    int l=0, r=1e9+1, ans=INF;
    while(l<=r) {
        const int mid=(l+r)>>1;
        if(ok(mid)) {
            ans=min(ans, mid);
            r=mid-1;
        } else {
            l=mid+1;
        }
    }
    assert(ans!=INF);
    cout<<ans<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}