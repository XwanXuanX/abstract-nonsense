// Problem: D. Christmas Tree Decoration
// Contest: Codeforces - Educational Codeforces Round 186 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/2182/D
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
#define MOD 998244353

#ifndef ONLINE_JUDGE
    #include "debug.hpp"
    #define debug(...) do { __VA_ARGS__ } while (0)
#else
    #define debug(...) do {} while (0)
#endif

int modpow(int a, int e) {
    int res=1;
    while(e) {
        if(e&1) res=1ll*res*a%MOD;
        a=1ll*a*a%MOD;
        e>>=1;
    }
    return res;
}

int nCr(int n, int r) {
    if(r<0 || r>n) return 0;
    if(r==0 || r==n) return 1;
    if(r>n-r) r=n-r;
    int num=1, den=1;
    for (int i=0; i<r; i++) {
        num=1ll*num*(n-i)%MOD;
        den=1ll*den*(i+1)%MOD;
    }
    return 1ll*num*modpow(den, MOD-2)%MOD;
}

int factorial(int n) {
    int res=1;
    for(int i=2; i<=n; i++) {
        res=1ll*res*i%MOD;
    }
    return res;
}

//6 1 4 2 1 = 14/4 = 3.5
//3 4 4 3 -> 4 4 3 3 -> 0 0 0 0
//need to distribute the decor in box 0 to other boxes to make them even
//count the number of ways to distribute
//1 2 1 -> (4) 4 3 3 = 4
//1 2 1 -> (4) 3 4 3 = 4
//1 2 1 -> (4) 3 3 4 = 4 -> 3*4 = 12 ways
void solve() {
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i=0; i<n+1; ++i) cin>>a[i];
    int sum=accumulate(a.begin(),a.end(),0ll);
    int base=sum/n, rem=sum%n; //all n need base, all rem need base+1
    vector<int> b;
    int sat_rem=0;
    for(int i=1; i<n+1; ++i) {
        if(a[i]>base+1) { //illegal
            cout<<0<<'\n';
            return;
        }
        if(a[i]==base+1) {
            sat_rem++;
            continue; //those are fixed
        }
        b.push_back(a[i]);
    }
    //1 2 2 0 -> 2 2 1
    //5/3=1 5%3=2
    if(sat_rem>rem) {
        cout<<0<<'\n';
        return;
    }
    int base_need=n-rem, rem_need=rem-sat_rem;
    assert(base_need*base + rem_need*(base+1) - accumulate(b.begin(),b.end(),0ll) == a[0]);
    //need to choose base_need from b and rem_need from b
    int ways=nCr(b.size(),rem_need);
    //and in each ways, we can freely arrange items in two partition
    int fact1=factorial(rem), fact2=factorial(base_need);
    cout<<1ll*ways*fact1%MOD*fact2%MOD<<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    int T=1; cin>>T;
    while(T--) solve();
}