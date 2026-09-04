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

struct P{
        int x,y,z;
};

void solve() {
        int n;
        cin>>n;
        vector<P> p(n);
        for(int i=0; i<n; ++i) {
                cin>>p[i].x>>p[i].y>>p[i].z;
        }
        int X=0,Y=0;
        for(int i=0; i<n; ++i) {
                if(p[i].x>p[i].y) X+=p[i].z;
                else Y+=p[i].z;
        }
        if(X>Y) {
                cout<<0<<'\n';
                return;
        }
        int Z=X+Y;
        int threshold=(Z/2 + 1)-X;
        vector<pair<int,int>> pp;
        auto cost=[&](P& a)->int{
                return ((a.x+a.y)/2 + 1)-min(a.x,a.y);
        };
        for(int i=0; i<n; ++i) {
                if(p[i].x<p[i].y)
                        pp.push_back({p[i].z,cost(p[i])});
        }
        //dp time!
        vector<int> dp(threshold+1,INF);
        dp[0]=0;
        for(int i=0; i<pp.size(); ++i) {
                vector<int> cp=dp;
                for(int j=0; j<threshold+1; ++j) {
                        if(dp[j]==INF)
                                continue;
                        int nv=min(threshold,j+pp[i].first);
                        cp[nv]=min(cp[nv],dp[j]+pp[i].second);
                }
                dp=cp;
        }
        cout<<dp[threshold]<<'\n';
        return;
}

signed main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int T=1; //cin>>T;
        while(T--) solve();
}
