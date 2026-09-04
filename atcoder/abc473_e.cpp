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
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0; i<n; ++i) {
                cin>>a[i];
        }
        vector<int> pref(n+1);
        for(int i=0; i<n; ++i) {
                pref[i+1]=(pref[i]+a[i])%k;
        }
        vector<int> nxt(n,-1);
        unordered_map<int,int> near;
        for(int i=n; i>=0; --i) {
                auto it=near.find(pref[i]);
                if(i<n && it!=near.end()) {
                        nxt[i]=it->second-1;
                }
                near[pref[i]]=i;
        }
        vector<int> dp(n,0);
        for(int i=0; i<n; ++i) {
                int prev=(i-1>=0) ? dp[i-1]:0;
                dp[i]=max(dp[i],prev);
                if(nxt[i]!=-1) {
                        dp[nxt[i]]=max(dp[nxt[i]],prev+1);
                }
        }
        cout<<dp[n-1]<<'\n';
        return;
}

signed main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int T=1; //cin>>T;
        while(T--) solve();
}
