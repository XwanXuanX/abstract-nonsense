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

//x#x..
//.x..x
//x#xx#
//notice that the problem is the same as finding the largest island
//1st bfs: find the largest connected component
//2nd bfs: find DOF from any node in the largest CC
void solve() {
        int n,m;
        cin>>n>>m;
        vector<string> a(n);
        for(int i=0; i<n; ++i) {
                cin>>a[i];
        }
        vector<string> b(a);
        for(int i=0; i<n; ++i) {
                for(int j=0; j<m; ++j) {
                        if(a[i][j]=='#') {
                                if(i>0) b[i-1][j]='#';
                                if(i<n-1) b[i+1][j]='#';
                                if(j>0) b[i][j-1]='#';
                                if(j<m-1) b[i][j+1]='#';
                        }
                }
        }
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
        auto dfs=[&](auto&& self,int i,int j, int& sz,set<pair<int,int>>& s)->void {
                if(vis[i][j]) return;
                vis[i][j]=true;
                sz++;
                for(int k=0; k<4; ++k) {
                        const int ni=i+dx[k], nj=j+dy[k];
                        if(ni<0||ni>=n||nj<0||nj>=m||vis[ni][nj]) continue;
                        if(b[ni][nj]=='#') {
                                s.insert({ni,nj});
                                continue;
                        }
                        self(self,ni,nj,sz,s);
                }
        };
        int ans=0;
        debug(print(b););
        for(int i=0; i<n; ++i) {
                for(int j=0; j<m; ++j) {
                        if(vis[i][j]||b[i][j]=='#') continue;
                        int sz=0;
                        set<pair<int,int>> s;
                        dfs(dfs,i,j,sz,s);
                        debug(print(sz););
                        ans=max(ans,sz+(int)s.size());
                }
        }
        if(ans>0) {
                cout<<ans<<'\n';
                return;
        }
        for(int i=0; i<n; ++i) {
                for(int j=0; j<m; ++j) {
                        if(a[i][j]=='.') {
                                cout<<1<<'\n';
                                return;
                        }
                }
        }
        cout<<0<<'\n';
        return;
}

signed main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int T=1; //cin>>T;
        while(T--) solve();
}
