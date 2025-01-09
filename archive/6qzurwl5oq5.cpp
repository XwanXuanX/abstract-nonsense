#include <bits/stdc++.h>
using namespace std;

int nadj(int i,int j,int n,int m){
    return (int)(i>0) + (int)(i<n-1) + (int)(j>0) + (int)(j<m-1);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                cin>>a[i][j];
        int bad=0;
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j){
                if(a[i][j]>0&&nadj(i,j,n,m)<a[i][j])
                    bad|=1;
                a[i][j]=nadj(i,j,n,m);
            }
        if(bad){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j)
                cout<<a[i][j]<<' ';
            cout<<'\n';
        }
    }
}