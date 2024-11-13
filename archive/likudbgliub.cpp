#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m,k;
    cin>>n>>m>>k;
    cout<<m*(m-1)/2<<endl;
    for(int i=1;i<=m;++i)
        for(int j=i+1;j<=m;++j)
            if(!k){
                cout<<i<<' '<<j<<endl;
            }else{
                cout<<j<<' '<<i<<endl;
            }
    return 0;
}