#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    vector<int> a;
    cin>>n>>k;
    a.resize(n);
    for(int i=0; i<n; ++i)
        cin>>a[i];
    for(int i=0; i<n; ++i){
        a[i]%=k;
        if(a[i]==0)
            a[i]=k;
    }
    vector<pair<int,int>> aa;
    for(int i=0; i<n; ++i){
        aa.push_back(make_pair(a[i],-(i+1)));
    }
    sort(aa.rbegin(),aa.rend());
    for(int i=0; i<n; ++i)
        cout<<-aa[i].second<<' ';
    cout<<'\n';
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