// Problem: B. Array Fix
// Contest: Codeforces - Educational Codeforces Round 163 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1948/B
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
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    vector<int> res;
    if(a[0]<10) {
        res.push_back(a[0]);
    } else {
        int d2=a[0]%10, d1=(a[0]/10)%10;
        if(d1<=d2) res.push_back(d1), res.push_back(d2);
        else res.push_back(a[0]);
    }
    for(int i=1; i<n; ++i) {
        int bk=res.back();
        if(a[i]<10) {
            if(bk>a[i]) {
                cout<<"NO\n";
                return;
            }
            res.push_back(a[i]);
        } else {
            int d2=a[i]%10, d1=(a[i]/10)%10;
            if(d1<=d2) {
                if(bk<=d1) {
                    res.push_back(d1), res.push_back(d2);
                } else {
                    //a[i] cannot be splitted
                    if(bk>a[i]) {
                        cout<<"NO\n";
                        return;
                    }
                    res.push_back(a[i]);
                }
            } else {
                if(bk>a[i]) {
                    cout<<"NO\n";
                    return;
                }
                res.push_back(a[i]);
            }
        }
    }
    cout<<"YES\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}