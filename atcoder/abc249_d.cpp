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
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; ++i) {
                cin>>a[i];
        }
        unordered_map<int,int> cnt;
        for(int x:a) {
                cnt[x]++;
        }
        vector<int> d;
        for(auto& p:cnt) {
                d.push_back(p.first);
        }
        sort(d.begin(),d.end());
        int ans=0;
        for(int i=0; i<(int)d.size(); ++i) {
                for(int j=0; j<(int)d.size(); ++j) {
                        if(d[i]*d[j]>2e5) {
                                break;
                        }
                        ans+=cnt[d[i]]*cnt[d[j]]*cnt[d[i]*d[j]];
                }
        }
        cout<<ans<<'\n';
}

signed main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int T=1; //cin>>T;
        while(T--) solve();
}
