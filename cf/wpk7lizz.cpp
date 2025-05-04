#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        string t,ans;
        cin>>t;
        int has0=0,has1=0;
        for(int i=0; i<t.size(); ++i){
            if(t[i]=='1')
                has1|=1;
            else if(t[i]=='0')
                has0|=1;
        }
        if(has1&&!has0 || has0&&!has1){
            cout<<t<<'\n';
            continue;
        }
        // this will guarentee k=2
        for(int i=0; i<t.size(); ++i){
            ans.push_back('1');
            ans.push_back('0');
        }
        cout<<ans<<'\n';
    }
}