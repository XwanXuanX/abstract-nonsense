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
        int n,m,c;
        cin>>n>>m>>c;
        vector<int> a(n);
        for(int i=0; i<n; ++i) {
                cin>>a[i];
        }
        map<int,int> cnt;
        for(int i=0; i<n; ++i) {
                cnt[a[i]]++;
        }
        int id=0;
        unordered_map<int,int> imp;
        for(auto&& p:cnt) {
                imp[id]=p.first;
                id++;
        }
        //debug(print(imp););
        const int cntl=cnt.size();
        vector<int> pfs(cntl,0);
        for(int i=0; i<cntl; ++i) {
                pfs[i]=cnt[imp[i]];
        }
        for(int i=1; i<cntl; ++i) {
                pfs[i]+=pfs[i-1];
        }
        int ans=0;
        for(int i=0; i<cntl; ++i) {
                const int sf=pfs.back()-pfs[i];
                int x=0;
                if(sf >= c) {
                        auto it=lower_bound(pfs.begin()+i+1,pfs.end(),pfs[i]+c);
                        x=*it-pfs[i];
                } else {
                        assert(pfs[i]+sf >= c);
                        const int need=c-sf;
                        auto it=lower_bound(pfs.begin(),pfs.begin()+i+1,need);
                        x=*it+sf;
                }
                int ni=(i+1)%cntl;
                int gap=(imp[ni]-imp[i]+m)%m;
                if(gap==0) gap=m;
                ans+=gap*x;
        }
        cout<<ans<<'\n';
        return;
}

signed main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int T=1; //cin>>T;
        while(T--) solve();
}
