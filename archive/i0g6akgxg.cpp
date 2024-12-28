#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    vector<int> a;
    cin>>n>>k;
    a.resize(n);
    for(int i=0; i<n; ++i)
        cin>>a[i];
    sort(a.begin(),a.end());
    vector<int> b;
    for(int i=1; i<n; ++i){
        if(a[i]-a[i-1]>k)
            b.push_back(i-1);
    }
    b.insert(b.begin(),-1);
    b.push_back(n-1);
    int ans=INT_MIN;
    for(int i=1; i<b.size(); ++i){
        ans=max(ans,b[i]-b[i-1]);
    }
    cout<<n-ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
}