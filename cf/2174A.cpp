// Problem: A. Needle in a Haystack
// Contest: Codeforces - Codeforces Round 1069 (Div. 1)
// URL: https://codeforces.com/problemset/problem/2174/A
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

void solve() {
    string s,t; cin>>s>>t;
    unordered_map<char,int> cntt,cnts;
    for(auto&& c:t) {
        cntt[c]++;
    }
    for(auto&& c:s) {
        cnts[c]++;
    }
    for(auto&& p:cnts) {
        if(p.second>cntt[p.first]) {
            cout<<"Impossible\n";
            return;
        }
        cntt[p.first]-=p.second;
    }
    vector<char> rem;
    for(auto&& p:cntt) {
        for(int i=0; i<p.second; ++i) {
            rem.push_back(p.first);
        }
    }
    sort(rem.begin(),rem.end());
    int i=0,j=0;
    string ans;
    while(i<s.size()&&j<rem.size()) {
        if(s[i]<=rem[j]) {
            ans.push_back(s[i++]);
        } else {
            ans.push_back(rem[j++]);
        }
    }
    if(i<s.size()) {
        while(i<s.size()) {
            ans.push_back(s[i++]);
        }
    }
    if(j<rem.size()) {
        while(j<rem.size()) {
            ans.push_back(rem[j++]);
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