#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    vector<int> a;
    cin>>n>>k;
    a.resize(n);
    for(int i=0; i<n; ++i)
        cin>>a[i];
    map<int,vector<int>> ps;
    for(int i=0; i<n; ++i){
        ps[a[i]].push_back(i+1);
    }
    int ans=INT_MAX;
    for(auto& p:ps){
        p.second.insert(p.second.begin(),0);
        p.second.push_back(n+1);
        priority_queue<int,vector<int>,less<int>> pq;
        for(int i=1; i<p.second.size(); ++i){
            pq.push(p.second[i]-p.second[i-1]-1);
        }
        int mx=pq.top();
        pq.pop();
        pq.push((mx-1)/2);
        pq.push((mx-1)-((mx-1)/2));
        ans=min(ans,pq.top());
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