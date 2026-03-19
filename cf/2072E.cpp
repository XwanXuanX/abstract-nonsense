// Problem: E. Do You Love Your Hero and His Two-Hit Multi-Target Attacks?
// Contest: Codeforces - Codeforces Round 1006 (Div. 3)
// URL: https://codeforces.com/problemset/problem/2072/E
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

void solve() {
    int n; cin>>n;
    vector<int> comb(1001,0);
    for(int i=2; i<=1000; ++i) {
        comb[i]=(i*(i-1))/2;
    }
    if(n==0) {
        cout<<0<<'\n';
        return;
    }
    //given a target, find the largest (n*(n-1))/2 <= target, return n and (n*(n-1))/2
    auto handle=[&](int tar)->pair<int,int> {
        int l=2, r=1000, ans=0;
        while(l<=r) {
            int mid=(l+r)>>1;
            if(comb[mid]<=tar) {
                ans=max(ans,mid);
                l=mid+1;
            } else {
                r=mid-1;
            }
        }
        assert(comb[ans]<=tar);
        return {ans,comb[ans]};
    };
    unordered_map<int,vector<int>> pos;
    //initial placement: form the rows
    auto[r,c]=handle(n);
    n-=c; //reduce n by c combinations
    int row=0, col=1;
    for(int i=0; i<r; ++i) {
        pos[row++].push_back(0);
    }
    row=0;
    while(n) {
        auto[r,c]=handle(n);
        n-=c; //reduce n by c combinations
        //put r-1 in the next empty row
        //between rows, need to make sure the columns are disjoint
        //so maintain the col pointer to make them non-overlapping
        for(int i=0; i<r-1; ++i) {
            pos[row].push_back(col++);
        }
        row++;
    }
    vector<pair<int,int>> ans;
    for(auto&& p:pos) {
        for(auto&& y:p.second) {
            ans.push_back({p.first,y});
        }
    }
    cout<<ans.size()<<'\n';
    for(auto&&[x,y]:ans) {
        cout<<x<<' '<<y<<'\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}