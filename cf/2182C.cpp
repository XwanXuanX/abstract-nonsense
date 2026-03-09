// Problem: C. Production of Snowmen
// Contest: Codeforces - Educational Codeforces Round 186 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/2182/C
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#if defined(__GNUC__) && !defined(__clang__)
    #pragma GCC optimize("Ofast,unroll-loops")
    #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma")
#endif
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF (1ll<<60)

#ifndef ONLINE_JUDGE
    #include "debug.hpp"
    #define debug(...) do { __VA_ARGS__ } while (0)
#else
    #define debug(...) do {} while (0)
#endif

void solve() {
    int n; cin>>n;
    vector<int> a(n),b(n),c(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    for(int i=0; i<n; ++i) cin>>b[i];
    for(int i=0; i<n; ++i) cin>>c[i];
    auto handle=[&](vector<int>& t, vector<int>& b)->vector<int>{
        auto check=[&](int i, int j)->bool {
            if(t[i]>=b[j]) {
                return false;
            }
            for(int ii=(i+1)%n, jj=(j+1)%n; ii!=i&&jj!=j; ii=(ii+1)%n, jj=(jj+1)%n) {
                if(t[ii]>=b[jj]) {
                    return false;
                }
            }
            return true;
        };
        int ans=0;
        for(int i=0; i<n; ++i) {
            if(check(i,0)){
                ans++;
            }
        }
        vector<int> ret(n,ans);
        return ret;
    };
    auto v1=handle(a,b), v2=handle(b,c);
    int ans=0;
    for(int i=0; i<n; ++i) {
        ans+=v1[i]*v2[i];
    }
    cout<<ans<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}