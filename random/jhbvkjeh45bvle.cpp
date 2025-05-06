#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,a,g,A=0,G=0;
    cin>>n;
    string ans;
    for(int i=0;i<n;++i){
        cin>>a>>g;
        if(A+a-G>500){ // then you need to incremement the other side to control difference under 500
            G+=g;
            ans.push_back('G');
        }else{
            A+=a;
            ans.push_back('A');
        }
    }
    cout<<ans<<endl;
    return 0;
}