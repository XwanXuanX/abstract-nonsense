// Problem: C. Odd Process
// Contest: Codeforces - Codeforces Round 1070 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2176/C
// Memory Limit: 256 MB
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

/*
k=1 -> take largest odd
k=2 -> take largest odd and largest even
k=3 -> take one more even
and so on...
*/
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    vector<int> o,e;
    for(int i=0; i<n; ++i) {
        if(a[i]%2) {
            o.push_back(a[i]);
        } else {
            e.push_back(a[i]);
        }
    }
    if(o.empty()) {
        for(int i=0; i<n; ++i) cout<<0<<' ';
        cout<<'\n';
        return;
    }
    if(e.empty()) {
        int mx=*max_element(o.begin(),o.end());
        for(int i=0; i<n; ++i) cout<<(i%2==0?mx:0)<<' ';
        cout<<'\n';
        return;
    }
    sort(o.begin(),o.end(),greater<int>());
    sort(e.begin(),e.end(),greater<int>());
    vector<int> ans(n);
    ans[0]=o[0];
    //take as many even as possible on the prefix
    int ub=0;
    for(int i=1; i<=e.size(); ++i) {
        ans[i]+=ans[i-1]+e[i-1];
        ub=max(ub,ans[i]);
    }
    //we've reached the upper bound, and there is at least one even
    //so we can get the sub-upperbound by ub-e.back();
    int subub=ub-e.back();
    for(int i=e.size()+1; i<n; ++i) {
        if(ans[i-1]==ub) {
            ans[i]=subub;
        } else {
            ans[i]=ub;
        }
    }
    //lastly, if odd number of odds, then you can always achieve ub
    //otherwise, it would be just 0
    if(o.size()%2==0) {
        ans.back()=0;
    }
    for(int i=0; i<n; ++i) cout<<ans[i]<<' ';
    cout<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}