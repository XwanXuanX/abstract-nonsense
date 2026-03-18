// Problem: A. Against the Difference
// Contest: Codeforces - Codeforces Round 1046 (Div. 1)
// URL: https://codeforces.com/problemset/problem/2135/A
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

//2 3 3 1 2 3 5 1 1 7
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    map<int,vector<int>> pos;
    for(int i=0; i<n; ++i) {
        pos[a[i]].push_back(i);
    }
    //how many seg in total? N n1 and M n2 -> O(N)+O(M) segments -> O(N+M) total length -> good
    vector<tuple<int,int,int>> seg; //[l,r,w]
    for(auto&& p:pos) {
        auto& b=p.second;
        for(int i=0; i<b.size(); ++i) {
            if(i+p.first-1>=b.size()) break;
            seg.push_back({b[i],b[i+p.first-1],p.first});
        }
    }
    // debug(print(seg);); //seems about right
    //if no candidate, automatically 0
    if(seg.size()==0) {
        cout<<0<<'\n';
        return;
    }
    sort(seg.begin(),seg.end());
    auto find=[&](int i)->int {
        int l=i+1, r=seg.size()-1, ans=seg.size();
        while(l<=r) {
            int mid=(l+r)>>1;
            if(get<0>(seg[mid])>get<1>(seg[i])) {
                ans=mid, r=mid-1;
            } else {
                l=mid+1;
            }
        }
        return ans;
    };
    vector<int> dp(seg.size()+1,0);
    for(int i=seg.size()-1; i>=0; --i) {
        int next=find(i);
        int take=get<2>(seg[i])+dp[next], skip=dp[i+1];
        dp[i]=max(take,skip);  
    }
    cout<<dp[0]<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}