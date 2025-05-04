#include <bits/stdc++.h>
using namespace std;

bool overlap(pair<int,int> p,pair<int,int> q){
    return p.first<=q.second && q.first<=p.second;
}

bool ok(vector<pair<int,int>>&a,int k){
    pair<int,int> reach(0,0);
    for(int i=0; i<a.size()-1; ++i){
        reach.first=max(0,reach.first-k);
        reach.second=reach.second+k;
        if(!overlap(reach,a[i+1])){
            return false;
        }
        reach.first=max(reach.first,a[i+1].first);
        reach.second=min(reach.second,a[i+1].second);
    }
    return true;
}

void solve(){
    int n;
    vector<pair<int,int>> a;
    cin>>n;
    a.resize(n);
    for(int i=0; i<n; ++i)
        cin>>a[i].first>>a[i].second;
    a.insert(a.begin(),make_pair(0,0));
    int l=0,r=1e9;
    while(l<=r){
        int mid=(l+r)/2;
        if(ok(a,mid)){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<l<<'\n';
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