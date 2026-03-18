// Problem: B. Two Large Bags
// Contest: Codeforces - Codeforces Round 1004 (Div. 2)
// URL: https://codeforces.com/problemset/problem/2067/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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

//if a contains even number for each number iniaitlly, then yes
//otherwise, you need to try to make another number that has odd occurence
//1. move something to the second bag
//2. inc number by 1, target should be 1 larger than initial. then move one target to second, and you can make target+1 now
//
//3 3 4 5 3 3
//3 3 4 5 3          3 (4 and 5)
//3 4 4 5 3
//3 4 5 3            3 4
//5 4 5 3            3 4
//4 5 3              3 4 5
//
//1 1 1 1 1 1 1 4
//1 1 1 1 1 1 4      1
//2 2 2 2 2 1 4      1
//2 2 2 2 1 4        1 2
//3 3 3 2 1 4        1 2
//3 3 2 1 4          1 2 3
//4 3 2 1 4          1 2 3
//3 2 1 4            1 2 3 4
//
//if I want to make a number b from a, b>a, then I need a, a+1, a+2, ...b-1 in second bag
//1 1 1 1 4 4 4 4
//1 1 1 4 4 4 4            1
//2 2 1 4 4 4 4            1
//2 1 4 4 4 4              1 2
//2 1 4 4 4                1 2 4
//2 1 4 5 5                1 2 4
//2 1 4 5                  1 2 4 5
void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    //O(n^2) method is acceptable, so we can brute force it!
    map<int,int> f,s;
    for(int i=0; i<n; ++i) {
        f[a[i]]++;
    }
    auto it=f.begin();
    while(it!=f.end()) {
        // debug(print(it->first););
        assert(it->second>0);
        if(it->second==1) {
            cout<<"No\n";
            return;
        }
        //move one to the second bag
        f[it->first]--;
        s[it->first]++;
        //inc n-1 the rest
        int to_inc=f[it->first]-1;
        if(to_inc) {
            f[it->first]-=to_inc;
            f[it->first+1]+=to_inc; //NOTE: inserting element to map while iterating is not UB!
        }
        it++;
    }
    cout<<"Yes\n";    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}