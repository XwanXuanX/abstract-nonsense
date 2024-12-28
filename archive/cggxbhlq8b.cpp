#include <bits/stdc++.h>
using namespace std;

void fill(vector<pair<int,int>>& seg, vector<int>& a){
    int s=0;
    for(int i=1; i<a.size(); ++i){
        if(a[i]!=a[i-1]){
            seg.push_back(make_pair(s,i-1));
            s=i;
        }
    }
    seg.push_back(make_pair(s,a.size()-1));
}

void solve(){
    int n;
    vector<int> a,b;
    cin>>n;
    a.resize(n);
    b.resize(n);
    for(int i=0; i<n; ++i)
        cin>>a[i];
    for(int i=0; i<n; ++i)
        cin>>b[i];
    vector<pair<int,int>> as,bs;
    fill(as,a);
    fill(bs,b);
    map<int,int> amx,bmx;
    for(int i=0; i<as.size(); ++i){
        amx[a[as[i].first]]=max(amx[a[as[i].first]],as[i].second-as[i].first+1);
    }
    for(int i=0; i<bs.size(); ++i){
        bmx[b[bs[i].first]]=max(bmx[b[bs[i].first]],bs[i].second-bs[i].first+1);
    }
    int ans=0;
    for(int i=0; i<=2*n; ++i){
        ans=max(ans,amx[i]+bmx[i]);
    }
    cout<<ans<<'\n';
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