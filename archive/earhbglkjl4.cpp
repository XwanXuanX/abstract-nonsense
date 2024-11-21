#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];

    map<int,vector<int>> adj;
    map<int,int> cnt;
    for(int i=0;i<n;++i){ // find the adj element for each position
        cnt[a[i]] = 0;
        for(int j=i+a[i];j<n;j+=a[i]) if(a[j] > a[i]) adj[a[j]].push_back(a[i]), cnt[a[i]]++;
        for(int j=i-a[i];j>=0;j-=a[i]) if(a[j] > a[i]) adj[a[j]].push_back(a[i]), cnt[a[i]]++;
    }

    deque<int> q;
    vector<int> indeg(n+1, 0);
    vector<int> ans(n+1, true);
    for(int i=1;i<=n;++i) for(auto node:adj[i]) indeg[node]++;
    for(int i=1;i<=n;++i) if(indeg[i] == 0) q.push_back(i);
    while(q.size()){
        int node = q.front(); q.pop_front();
        for(auto it:adj[node]){
            indeg[it]--;
            ans[it] &= (!ans[node]);
            if(indeg[it] == 0) q.push_back(it);
        }
    }

    for(int i=0;i<n;++i) if(ans[a[i]]) cout<<'B'; else cout<<'A';
    return 0;
}