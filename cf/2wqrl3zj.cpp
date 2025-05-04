#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    sort(a.begin(), a.end(), greater<int>());
    int gap=0, ans=0;
    for(int i=0; i<n; ++i) if(i%2) ans-=a[i]; else ans+=a[i];
    for(int i=1; i<n; i+=2) gap += (a[i-1]-a[i]);
    cout<<ans-min(gap,k)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}