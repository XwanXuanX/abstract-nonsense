#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

using Grid = vector<vector<int>>;

void dfs(int i, int j, int c, int& sz, Grid& a, Grid& vis) {
    vis[i][j] |= 1;
    sz++;
    int n=a.size(), m=a[0].size();
    for (int k=0; k<4; ++k) {
        int ni=i+dx[k], nj=j+dy[k];
        if(ni<0 || ni>=n || nj<0 || nj>=m || a[ni][nj]!=c || vis[ni][nj]){
            continue;
        }
        dfs(ni, nj, c, sz, a, vis);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n,m;
        cin>>n>>m;
        Grid a(n, vector<int>(m));
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                cin>>a[i][j];
            }
        }

        map<int,int> mp;
        Grid vis(n, vector<int>(m, false));
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(vis[i][j]){
                    continue;
                }
                int sz=0;
                dfs(i, j, a[i][j], sz, a, vis);
                assert(sz > 0);
                if (mp.count(a[i][j])) {
                    if(sz >= 2){
                        mp[a[i][j]] = 2;
                    }
                } else {
                    if(sz >= 2){
                        mp[a[i][j]] = 2;
                    } else {
                        mp[a[i][j]] = 1;
                    }
                }
            }
        }

        vector<int> step;
        for(auto& p:mp) {
            step.push_back(p.second);
        }
        int sum = accumulate(step.begin(), step.end(), 0);

        int ans=INT_MAX;
        for(int i=0; i<step.size(); ++i) {
            ans = min(ans, sum-step[i]);
        }

        cout<<ans<<'\n';
    }
}