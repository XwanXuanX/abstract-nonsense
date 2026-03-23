// Problem: E. Triple Operations
// Contest: Codeforces - Codeforces Round 964 (Div. 4)
// URL: https://codeforces.com/problemset/problem/1999/E
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

//you should make one number 0 first, then make the rest 0
vector<int> p3;
vector<int> pfs, nop;

class SparseTable {
private:
    int n;
    int max_log;
    std::vector<std::vector<int>> st;
    std::vector<int> logs;

public:
    SparseTable(const std::vector<int>& arr) {
        n = arr.size();
        logs.resize(n + 1);
        logs[1] = 0;
        for (int i = 2; i <= n; i++)
            logs[i] = logs[i / 2] + 1;
        max_log = logs[n] + 1;
        st.assign(n, std::vector<int>(max_log));
        for (int i = 0; i < n; i++)
            st[i][0] = arr[i];
        for (int j = 1; j < max_log; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = std::min(st[i][j - 1], 
                                    st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int L, int R) {
        int j = logs[R - L + 1];
        return std::min(st[L][j], st[R - (1 << j) + 1][j]);
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cin.exceptions(cin.failbit);
    p3.assign(20,0);
    p3[0]=1;
    for(int i=1; i<20; ++i) {
        p3[i]=p3[i-1]*3;
    }
    pfs.resize(2e5 + 10), nop.resize(2e5 + 10);
    for(int i=1; i<=2e5; ++i) {
        const int op=upper_bound(p3.begin(),p3.end(),i)-p3.begin();
        nop[i]=op, pfs[i]=op;
    }
    for(int i=1; i<=2e5; ++i) {
        pfs[i]+=pfs[i-1];
    }
    SparseTable st(nop);
    int T=1; cin>>T;
    while(T--) {
        int l,r; cin>>l>>r;
        cout<< pfs[r]-pfs[l-1] + st.query(l,r) << '\n';
    }
}