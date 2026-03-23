// Problem: C. Remove the Ends
// Contest: Codeforces - Codeforces Round 1005 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2064/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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

//positive prefix and negative suffix will be added for sure
//partition a into positive and negative segments
//when you choose an element in the segment, you can always get the entire segment
//but you will lose the segment before/after it
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    vector<int> sign(n);
    for(int i=0; i<n; ++i) sign[i]=a[i]>0 ? 1:-1;
    vector<pair<int,int>> seg;
    int start=0;
    for(int i=1; i<n; ++i) if(sign[i]!=sign[i-1]) {
        seg.push_back({start,i-1});
        start=i;
    }
    seg.push_back({start,n-1});
    // debug(print(seg););
    vector<int> pfs(n,0);
    for(int i=0; i<n; ++i) pfs[i]=abs(a[i]);
    for(int i=1; i<n; ++i) pfs[i]+=pfs[i-1];
    auto sum=[&](pair<int,int>& s)->int {
        auto[l,r]=s;
        return pfs[r]-(l==0 ? 0:pfs[l-1]);
    };
    vector<int> dp(seg.size(),0);
    dp[0]=sum(seg[0]);
    for(int i=1; i<seg.size(); ++i) {
        dp[i]=max(dp[i], sum(seg[i]));
        if(sign[seg[i].first]==1) { //+ can only propogate from +
            if(i-2>=0) dp[i]=max(dp[i], dp[i-2]+sum(seg[i]));
        } else { //- can propogate from - and +
            if(i-1>=0) dp[i]=max(dp[i], dp[i-1]+sum(seg[i]));
            if(i-2>=0) dp[i]=max(dp[i], dp[i-2]+sum(seg[i]));
        }
    }
    int ans=0;
    for(int i=0; i<dp.size(); ++i) ans=max(ans,dp[i]);
    cout<<ans<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}