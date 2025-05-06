#include <bits/stdc++.h>
using namespace std;

int n,m,k;

void solve(){
    cin>>n>>m>>k;

    vector<int> ans;
    while(n>m){
        ans.push_back(n);
        n--;
    }

    for(int i=1; i<=n; ++i)
        ans.push_back(i);
    
    for(int i=0; i<ans.size(); ++i)
        cout<<ans[i]<<' ';
    cout<<'\n';
}

signed main(){
    int t; cin>>t;
    while(t--) solve();
}