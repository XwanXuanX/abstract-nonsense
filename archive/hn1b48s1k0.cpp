#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n,m;
        cin>>n>>m;
        vector<string> ans(n);
        for(int i=0,b=1; i<n; ++i){
            if(b){
                for(int j=0; j<m; ++j)
                    ans[i].push_back(j%2?'W':'B');
                b=0;
            }else{
                for(int j=0; j<m; ++j)
                    ans[i].push_back(j%2?'B':'W');
                b=1;
            }
        }
        if((n*m)%2==0){
            if(m%2==0)
                ans[0][m-1]='B';
            else if(n%2==0)
                ans[n-1][0]='B';
        }
        for(int i=0; i<n; ++i)
            cout<<ans[i]<<'\n';
    }
}