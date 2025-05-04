#include <bits/stdc++.h>
using namespace std;
#define int long long

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<string> mat(n);
    for(int i=0;i<n;++i)
        cin>>mat[i];
    
    function<bool(int i,int j,int pi, int pj, vector<vector<bool>>& vis)> dfs;
    dfs=[&](int i,int j,int pi, int pj, vector<vector<bool>>& vis)->bool{
        vis[i][j] = true;
        for(int k=0;k<4;++k){
            int ni=i+dx[k], nj=j+dy[k];
            if(ni<0||ni>=n || nj<0||nj>=m || (ni==pi && nj==pj) || mat[ni][nj] != mat[i][j])
                continue;
            if(vis[ni][nj])
                return true;
            else if(dfs(ni,nj,i,j,vis))
                return true;
        }
        return false;
    };
    
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j){
            vector<vector<bool>> vis(n,vector<bool>(m,false));
            if(dfs(i,j,-1,-1,vis)){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    
    cout<<"No"<<endl;
    return 0;
}

/**
 * for each of the cell we can do a full dfs search to check validity
 * it's completely fine... very bad solution tho...
 */