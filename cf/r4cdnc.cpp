#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n,l,r;
        cin>>n>>l>>r;
        vector<int> ans;
        int imp=0;
        for(int i=1; i<=n; ++i){
            if((r/i)*i >= l){
                ans.push_back(i*(r/i));
            }else{
                imp|=1;
            }
        }
        if(imp){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
            for(int i=0; i<n; ++i){
                cout<<ans[i]<<' ';
            }
            cout<<'\n';
        }
    }   
}

// all distinct means that gcd(i,a[i]) == i
// this is the only way to achieve it -> a[i] should be a multiple of i
// how to find a multiple of something that is in the range