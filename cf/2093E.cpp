// Problem: E. Min Max MEX
// Contest: Codeforces - Codeforces Round 1016 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2093/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC optimize("Ofast,unroll-loops")
#endif
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
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    auto check=[&](const int x)->bool {
        int MEX=0, seg=0;
        safe_map<int,int> cnt;
        for(int i=0; i<n; ++i) {
            if(a[i]<x) {
                cnt[a[i]]++;
                while(cnt[MEX]!=0) {
                    MEX++;
                }
            }
            if(MEX>=x) {
                seg++;
                if(seg==k) return true;
                MEX=0;
                cnt.clear();
            }
        }
        return seg>=k;
    };
    int l=0, r=n+1, ans=-INF;
    while(l<=r) {
        const int mid=(l+r)>>1;
        if(check(mid)) {
            chmax(ans, mid);
            l=mid+1;
        } else {
            r=mid-1;
        }
    }
    cout<<ans<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}