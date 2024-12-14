#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];

    bool same=true;
    for(int i=0; i<n; ++i) same &= (a[i]==a[0]);
    if(same){cout<<-1<<endl; return;}

    if(a[0]!=a.back()){cout<<0<<endl; return;}
    int mn=INT_MAX;
    for(int i=0; i<n; ++i) if(a[i]!=a[0]) mn=min(mn, i);
    for(int i=n-1; i>=0; --i) if(a[i]!=a[0]) mn=min(mn, n-i-1);

    vector<int> p;
    for(int i=0; i<n; ++i) if(a[i]!=a[0]) p.push_back(i);
    if(p.size()>1)
        for(int i=1; i<p.size(); ++i)
            mn=min(mn, p[i]-p[i-1]-1);

    cout<<mn<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}