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
        vector<int> a;
        cin>>n;
        a.resize(n);
        for(int i=0; i<n; ++i)
            cin>>a[i];
        int ans=0,mn=a[n-1];
        for(int i=n-2; i>=0; --i){
            if(a[i]<=mn){
                mn=min(mn,a[i]);
                continue;
            }
            int k=ceil((double)a[i]/mn);
            ans+=(k-1);
            mn=min(mn,a[i]/k);
        }
        cout<<ans<<'\n';
    }
}