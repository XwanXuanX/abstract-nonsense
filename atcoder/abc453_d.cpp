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
        int n,m;
        cin>>n>>m;
        vector<string> mat(n);
        for(int i=0; i<n; ++i) {
                cin>>mat[i];
        }
        int si,sj;
        for(int i=0; i<n; ++i) {
                for(int j=0; j<m; ++j) {
                        if(mat[i][j]=='S') {
                                si=i, sj=j;
                        }
                }
        }
        vector<vector<vector<bool>>> vis(n,vector<vector<bool>>(m,vector<bool>(5,false)));
        int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
        char dir[4]={'D','U','R','L'};
        string path;
        auto valid=[&](int i,int j)->bool {
                return i>=0&&i<n&&j>=0&&j<m&&mat[i][j]!='#';
        };
        auto go=[&](auto&& dfs,int i,int j,int nxt)->bool {
                int ni=i+dx[nxt];
                int nj=j+dy[nxt];
                if(!valid(ni,nj)) return false;
                if(vis[ni][nj][nxt]) return false;
                path.push_back(dir[nxt]);
                if(dfs(dfs,ni,nj,nxt)) return true;
                path.pop_back();
                return false;
        };
        auto dfs=[&](auto&& self,int i,int j,int incomming)->bool {
                if(mat[i][j]=='G') {
                        return true;
                }
                vis[i][j][incomming]=true;
                if(mat[i][j]=='.'||mat[i][j]=='S') {
                        for(int k=0; k<4; ++k) {
                                if(go(self,i,j,k)) return true;
                        }
                } else if(mat[i][j]=='o') {
                        if(incomming<4&&go(self,i,j,incomming)) return true;
                } else if(mat[i][j]=='x') {
                        for(int k=0; k<4; ++k) {
                                if(k==incomming) continue;
                                if(go(self,i,j,k)) return true;
                        }
                }
                return false;
        };
        bool found=dfs(dfs,si,sj,5);
        if(found) cout<<"Yes\n"<<path<<'\n'; else cout<<"No\n";
}

signed main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int T=1; //cin>>T;
        while(T--) solve();
}
