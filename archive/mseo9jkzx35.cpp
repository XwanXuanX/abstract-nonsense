#include <bits/stdc++.h>
using namespace std;

bool same(int a,int b){
    return ((a%2)+(b%2))%2==0;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int a,b,c;
        cin>>a>>b>>c;
        vector<int> ans(3);
        ans[0]=same(b,c)?1:0;
        ans[1]=same(a,c)?1:0;
        ans[2]=same(a,b)?1:0;
        for(int i=0; i<3; ++i)
            cout<<ans[i]<<' ';
        cout<<'\n';
    }
}