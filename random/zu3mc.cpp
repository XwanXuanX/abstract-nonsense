// 1 99999 3444 0 3 8888
// 99998 + 3 + (8888-3)
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; ++i){
            cin>>a[i];
        }
        int ans=0;
        a.insert(a.begin(),0);
        for(int i=1; i<n+1; ++i){
            ans+=max(0ll,a[i]-a[i-1]);
        }
        cout<<ans-1<<'\n';



        
        // vector<int> zo;
        // for(int i=0; i<n; ++i){
        //     if(a[i]==0){
        //         zo.push_back(i);
        //     }
        // }
        // zo.push_back(n);
        // zo.insert(zo.begin(),-1);
        // int ans=0;
        // for(int i=1; i<zo.size(); ++i){
        //     int l=zo[i-1], r=zo[i];
        //     int mx=0;
        //     for(int j=l+1; j<r; ++j){
        //         if(a[j]>mx){
        //             ans+=(a[j]-mx);
        //             mx=max(mx,a[j]);
        //         }
        //     }
        // }
        // cout<<ans-1<<'\n';
    }
}