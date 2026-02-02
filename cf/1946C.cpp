// Problem: C. Tree Cutting
// Contest: Codeforces - Codeforces Round 936 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1946/C
// Memory Limit: 512 MB
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

//every cut is selecting a subtree
//optimal to cut the lowest subtree with size >= x
void solve() {
    int n,k; cin>>n>>k;
    vector<vector<int>> tr(n+1);
    for(int i=0; i<n-1; ++i) {
        int u,v; cin>>u>>v;
        tr[u].push_back(v), tr[v].push_back(u);
    }
    auto ok=[&](int x)->bool {
        int cut=0;
        auto dfs=[&](auto&& self, int nd, int par)->int {
            if(tr[nd].size()==1 && tr[nd][0]==par) {
                if(1>=x && cut<k) {
                    cut++;
                    return 0ll; // make the cut
                }
                return 1ll;
            }
            int nsub=0;
            for(auto&& adj:tr[nd]) {
                if(adj==par) continue;
                nsub+=self(self,adj,nd);
            }
            nsub++; // include itself
            if(nsub>=x && cut<k) {
                cut++;
                return 0ll; // make the cut
            }
            return nsub;
        };
        int root=dfs(dfs,1,0);
        if(cut<k) return false;
        return root>=x;
    };
    int l=0, r=n+1, ans=0;
    while(l<=r) {
        int mid=(l+r)>>1;
        if(ok(mid)) {
            ans=max(ans,mid);
            l=mid+1;
        } else {
            // debug(print(mid, "not ok"););
            r=mid-1;
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