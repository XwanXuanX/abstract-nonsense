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
        int n,m,sx,sy;
        cin>>n>>m>>sx>>sy;
        vector<pair<int,int>> h(n);
        vector<pair<char,int>> d(m);
        for(int i=0; i<n; ++i) {
                cin>>h[i].first>>h[i].second;
        }
        for(int i=0; i<m; ++i) {
                cin>>d[i].first>>d[i].second;
        }
        unordered_map<int,set<int>> hor,ver;
        for(int i=0; i<n; ++i) {
                hor[h[i].second].insert(h[i].first);
                ver[h[i].first].insert(h[i].second);
        }
        auto handle_hor=[&](int sy,int oldx,int newx)->int {
                int l=min(oldx,newx), r=max(oldx,newx);
                int ans=0;
                auto& st=hor[sy];
                auto it=st.lower_bound(l);
                while(it!=st.end() && *it<=r) {
                        int x=*it;
                        ans++;
                        ver[x].erase(sy);
                        it=st.erase(it);
                }
                return ans;
        };
        auto handle_ver=[&](int sx,int oldy,int newy)->int {
                int l=min(oldy,newy), r=max(oldy,newy);
                int ans=0;
                auto& st=ver[sx];
                auto it=st.lower_bound(l);
                while(it!=st.end() && *it<=r) {
                        int y=*it;
                        ans++;
                        hor[y].erase(sx);
                        it=st.erase(it);
                }
                return ans;
        };
        int ans=0;
        for(auto[dir,c] : d) {
                if(dir=='U') { //change sy
                        ans+=handle_ver(sx, sy, sy+c);
                        sy+=c;
                } else if(dir=='D') { //change sy
                        ans+=handle_ver(sx, sy, sy-c);
                        sy-=c;
                } else if (dir=='L') { //change sx
                        ans+=handle_hor(sy, sx, sx-c);
                        sx-=c;
                } else {
                        ans+=handle_hor(sy, sx, sx+c);
                        sx+=c;
                }
        }
        cout<<sx<<' '<<sy<<' '<<ans<<'\n';
        return;
}

signed main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int T=1; //cin>>T;
        while(T--) solve();
}
