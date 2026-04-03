// Problem: C. Raspberries
// Contest: Codeforces - Codeforces Round 905 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1883/C
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

//k==2,3,4,5
//2,3,5 are prime numbers, they must be included in the source numbers
//2->at most 1
//3->at most 2
//and so on
void solve() {
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    auto handle=[&](int o)->int {
        vector<int> op(n);
        for(int i=0; i<n; ++i) {
            if(a[i]%o==0) {
                return 0;
            }
            op[i]=(a[i]/o + 1) * o - a[i];
        }
        int ans=INF;
        for(int i=0; i<n; ++i) {
            ans=min(ans,op[i]);
        } 
        return ans;
    };
    if(k==2 || k==3 || k==5) {
        cout<<handle(k)<<'\n';
        return;
    }
    int mod=1;
    for(int i=0; i<n; ++i) {
        mod=((mod%4) * (a[i]%4)) % 4;
    }
    //if the original can form a 4, then good
    if(mod==0) {
        cout<<0<<'\n';
        return;
    }
    //k==4 is a special case, since it's not a prime
    //there are two ways to obtain a 4, 2*2, or 1*4
    cout<<min(handle(2)+1,handle(4))<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}