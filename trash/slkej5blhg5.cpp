#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> mat(n);
    for(int i=0;i<n;++i)
        cin>>mat[i];

    bool valid=true;
    for(int i=0;i<n;++i){
        int tile=0;
        for(int j=0;j<m;++j)       
            if(mat[i][j]!='.')
                tile++;
        if(tile%2)
            valid=false;
    }
    for(int j=0;j<m;++j){
        int tile=0;
        for(int i=0;i<n;++i)
            if(mat[i][j]!='.')
                tile++;
        if(tile%2)
            valid=false;
    }

    if(!valid){
        cout<<-1<<endl;
        return;
    }

    // construct the answer
    vector<string> ans(mat.begin(),mat.end());
    // LR
    for(int j=0;j<m-1;++j){
        int dom=0;
        for(int i=0;i<n;++i) // for each of the column we search for L if L exists then R also exists
            if(mat[i][j]=='L'){
                if(dom%2)
                    ans[i][j] = 'B', ans[i][j+1] = 'W';
                else
                    ans[i][j] = 'W', ans[i][j+1] = 'B';
                dom++;
            }
    }
    // UD
    for(int i=0;i<n-1;++i){
        int dom=0;
        for(int j=0;j<m;++j)
            if(mat[i][j]=='U'){
                if(dom%2)
                    ans[i][j] = 'B', ans[i+1][j] = 'W';
                else
                    ans[i][j] = 'W', ans[i+1][j] = 'B';
                dom++;
            }
    }


    for(int i=0;i<ans.size();++i)
        cout<<ans[i]<<endl;
    return;
}

/**
 * the key to this problem is the tiling in each row and column should cancel out each other
 * if the tile in each row and column are even, then we can construct the answer
 */

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}