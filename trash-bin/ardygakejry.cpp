#include <bits/stdc++.h>
using namespace std;
#define int long long

/**
 * how does the hunters know they can catch me?
 * if all the hunters are further to the exit than me, then non of them can hunt me
 * otherwise, hunters can simply go to the exit and wait me there (if they can reach there quicker)
 */

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

signed main(){
    int R,C;
    cin>>R>>C;
    vector<string> mat;
    string in;
    for(int i=0;i<R;++i){
        cin>>in;
        mat.push_back(in);
    }

    deque<pair<int,int>> q;
    vector<vector<bool>> vis(R,vector<bool>(C, false));
    // we should start the bfs search from the exit, so find the exit
    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j){
            if(mat[i][j]=='E'){
                q.push_back(make_pair(i,j));
                break;
            }
        }
    }
    auto valid=[&](int i,int j)->bool{ return 0<=i && i<R && 0<=j && j<C; };

    int ans=0;
    bool toofar=false;
    while(q.size()){
        if(toofar) // if hunters are farther to the exit, then ignore them.
            break;
        // we want to peel layer by layer, so...
        int sz=q.size();
        for(int _=0;_<sz;++_){
            auto [nodei, nodej]=q.front();
            q.pop_front();
            if(vis[nodei][nodej])
                continue;
            vis[nodei][nodej]=true;
            if(mat[nodei][nodej]=='S'){
                toofar=true;
            }else if(isdigit(mat[nodei][nodej]) && mat[nodei][nodej]>'0'){
                // we meet some hunters
                ans+=(mat[nodei][nodej]-'0');
            }
            // now explore the adjacent
            for(int k=0;k<4;++k){
                int ni=nodei+dx[k], nj=nodej+dy[k];
                if(!valid(ni,nj) || mat[ni][nj]=='T' || vis[ni][nj])
                    continue;
                q.push_back(make_pair(ni,nj));
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}