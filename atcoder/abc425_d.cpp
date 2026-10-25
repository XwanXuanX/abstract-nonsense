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

int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};

void solve() {
        int h,w;
        cin>>h>>w;
        vector<string> mat(h);
        for(int i=0; i<h; ++i) {
                cin>>mat[i];
        }
        queue<pair<int,int>> que;
        for(int i=0; i<h; ++i) {
                for(int j=0; j<w; ++j) {
                        if(mat[i][j]=='#')
                                que.push({i,j});
                }
        }
        auto handle=[&](int i,int j)->bool{
                int cnt=0;
                for(int k=0; k<4; ++k) {
                        int ni=i+dx[k],nj=j+dy[k];
                        if(ni<0||ni>=h||nj<0||nj>=w)
                                continue;
                        if(mat[ni][nj]=='#')
                                cnt++;
                }
                return cnt==1;
        };
        while(que.size()) {
                int sz=que.size();
                vector<pair<int,int>> update;
                while(sz--) {
                        auto[i,j]=que.front();
                        que.pop();
                        assert(mat[i][j]=='#');
                        for(int k=0; k<4; ++k) {
                                int ni=i+dx[k], nj=j+dy[k];
                                if(ni<0||ni>=h||nj<0||nj>=w||mat[ni][nj]=='#')
                                        continue;
                                if(handle(ni,nj)) {
                                        update.push_back({ni,nj});
                                        que.push({ni,nj});
                                }
                        }
                }
                for(int i=0; i<update.size(); ++i) {
                        mat[update[i].first][update[i].second]='#';
                }
        }
        int ans=0;
        for(int i=0; i<h; ++i) {
                for(int j=0; j<w; ++j) {
                        if(mat[i][j]=='#')
                                ans++;
                }
        }
        //debug(print(mat););
        cout<<ans<<'\n';
}

signed main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
        int T=1; //cin>>T;
        while(T--) solve();
}
