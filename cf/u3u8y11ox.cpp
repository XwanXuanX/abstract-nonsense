#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n,m;
        vector<string> mat;
        cin>>n>>m;
        mat.resize(n);
        for(int i=0; i<n; ++i)
            cin>>mat[i];
        // if the corners are already same color,
        // then we are done
        if(mat[0][0]==mat[n-1][m-1]||mat[0][m-1]==mat[n-1][0]){
            cout<<"YES\n";
            continue;
        }
        // otherwise, we need to check if we can make the four
        // corners the same color
        vector<bool> W(4,false),B(4,false);
        for(int i=0; i<m; ++i) // top row
            if(mat[0][i]=='W') W[0]=true;
            else B[0]=true;
        for(int i=0; i<m; ++i) // bot row
            if(mat[n-1][i]=='W') W[1]=true;
            else B[1]=true;
        for(int i=0; i<n; ++i) // left
            if(mat[i][0]=='W') W[2]=true;
            else B[2]=true;
        for(int i=0; i<n; ++i) // right
            if(mat[i][m-1]=='W') W[3]=true;
            else B[3]=true;
        // pair1
        if((W[0]&&W[2]&&W[1]&&W[3])||(B[0]&&B[2]&&B[1]&&B[3])){
            cout<<"YES\n";
            continue;
        }
        // pair2
        if((W[0]&&W[3]&&W[1]&&W[2])||(B[0]&&B[3]&&B[1]&&B[2])){
            cout<<"YES\n";
            continue;
        }
        cout<<"NO\n";
    }
}