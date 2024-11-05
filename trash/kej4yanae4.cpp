#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h,w,q;
    string in;
    vector<string> mat;
    cin>>h>>w;
    for(int i=0;i<h;++i)
        cin>>in, mat.push_back(in);
    
    // prep here
    auto hgood=[&](int i,int j)->int{ return j<w-1 && mat[i][j]=='.' && mat[i][j+1]=='.'; };
    auto vgood=[&](int i,int j)->int{ return i<h-1 && mat[i][j]=='.' && mat[i+1][j]=='.'; };
    // calc prefix matrix
    vector<vector<int>> dph(h,vector<int>(w,0));
    vector<vector<int>> dpv(h,vector<int>(w,0));

    auto fill=[w,h](vector<vector<int>>& dp, function<int(int,int)> p){
        dp[0][0] = p(0,0);
        for(int i=1;i<w;++i)
            dp[0][i] = dp[0][i-1] + p(0,i);
        for(int i=1;i<h;++i)
            dp[i][0] = dp[i-1][0] + p(i,0);
        for(int i=1;i<h;++i)
            for(int j=1;j<w;++j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + p(i,j);
    };

    // hor
    fill(dph, hgood);
    // ver
    fill(dpv, vgood);

    // queries
    auto query=[&](int x1,int y1,int x2,int y2, vector<vector<int>>& dp)->int{
        int t1 = (x1<=0) ? 0 : dp[x1-1][y2], t2 = (y1<=0) ? 0 : dp[x2][y1-1];
        int t3 = (x1 > 0 && y1 > 0) ? dp[x1-1][y1-1] : 0;
        return dp[x2][y2] - t1 - t2 + t3;
    };

    // process a single query
    auto proc=[&](int x1,int y1,int x2,int y2)->int{
        int h=0, v=0;
        if(y2-1 >= y1)
            h = query(x1,y1,x2,y2-1,dph);
        if(x2-1 >= x1)
            v = query(x1,y1,x2-1,y2,dpv);
        return h + v;
    };

    // process the query
    cin>>q;
    int x1,y1,x2,y2;
    for(int i=0;i<q;++i){
        cin>>x1>>y1>>x2>>y2;
        cout<<proc(x1-1,y1-1,x2-1,y2-1)<<endl;
    }

    return 0;
}

/**
 * this problem is tricky...
 */