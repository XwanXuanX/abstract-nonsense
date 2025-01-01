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
        a.insert(a.begin(),0);
        for(int i=1; i<=n; ++i)
            a[i]+=a[i-1];
        int ans=0;
        for(int i=1; i<=n; ++i){
            if(n%i)
                continue;
            int mx=LLONG_MIN,mn=LLONG_MAX;
            for(int j=i; j<=n; j+=i){
                mx=max(mx,a[j]-a[j-i]);
                mn=min(mn,a[j]-a[j-i]);
            }
            ans=max(ans,abs(mx-mn));
        }
        cout<<ans<<'\n';
    }
}