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

//x1 y1 y2 y3 x2
//combine (x1, x2) has the same cost as (x1,y1), (y1,y2), ...(y3,x2)
//so we can ignore the good ones and only focus on the missing pairs
//the problem is how to merge adjacent numbers together
void solve() {
        int n,k;
        cin>>n>>k;
        vector<int> a(k);
        for(int i=0; i<k; ++i) {
                cin>>a[i];
        }
        if((2*n-k)%2==0) {
                int ans=0;
                for(int i=0; i<k; i+=2) {
                        ans+=a[i+1]-a[i];
                }
                cout<<ans<<'\n';
                return;
        }
        vector<int> pfs(k+2,0),sfs(k+2,0);
        for(int i=2; i<=k; i+=2) {
                pfs[i]=pfs[i-2]+a[i-1]-a[i-2];
        }
        for(int i=k-2; i>=0; i-=2) {
                sfs[i]=sfs[i+2]+a[i+1]-a[i];
        }
        int ans=INF;
        for(int i=0; i<k; ++i) {
                if(i%2==0) {
                        ans=min(ans,pfs[i]+sfs[i+1]);
                } else {
                        ans=min(ans,pfs[i-1]+(a[i+1]-a[i-1])+sfs[i+2]);
                }
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
