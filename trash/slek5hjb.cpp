#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin>>mat[i][j];
    
    auto calc=[&](vector<int>& row)->int{ // calc the max of that row
        int mx=0, start=0;
        for(int i=1;i<m;++i)
            if(row[i] != row[i-1]){ // segment [start, i-1]
                if(row[start] == 1)
                    mx=max(mx, i-start);
                start = i;
            }
        // segment [start, row.size()-1]
        if(row[start] == 1)
            mx=max(mx, (int)row.size()-start);
        return mx;
    };

    vector<int> dp(n);
    for(int i=0;i<n;++i)
        dp[i] = calc(mat[i]);
    
    // start processing the queries
    int x,y;
    for(int i=0;i<q;++i){
        cin>>x>>y; x--, y--;
        mat[x][y] = !mat[x][y];
        // 500
        dp[x] = calc(mat[x]);
        // 500
        cout<<*max_element(dp.begin(), dp.end())<<endl;
    }

    return 0;
}

/**
 * obviously we need to do some preprocessing to not TLE
 * each update will update one row, so we can brute force it
 */