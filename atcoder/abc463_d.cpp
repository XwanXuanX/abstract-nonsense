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
        vector<pair<int,int>> a(n);
        for(int i=0; i<n; ++i) {
                cin>>a[i].first>>a[i].second;
        }
        sort(a.begin(),a.end(),[](pair<int,int>& p,pair<int,int>& q)->bool{
                        if(p.second!=q.second) return p.second < q.second;
                        return p.first < q.first;
                });
        auto ok=[&](int gap)->bool {
                int K=1;
                pair<int,int> prev=a[0];
                for(int i=1; i<n;++i) {
                        int dist=a[i].first-prev.second;
                        if(dist>=gap) {
                                prev=a[i];
                                K++;
                        }
                }
                return K>=k;
        };
        int l=1, r=INF, ans=0;
        while(l<=r) {
                int mid=(l+r)>>1;
                if(ok(mid)) {
                        ans=max(ans,mid);
                        l=mid+1;
                } else {
                        r=mid-1;
                }
        }
        if(ans==0) cout<<-1<<'\n'; else cout<<ans<<'\n';
        return;
}

signed main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int T=1; //cin>>T;
        while(T--) solve();
}
