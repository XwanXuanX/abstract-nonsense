#include <bits/stdc++.h>
using namespace std;

int n,k;

void solve(){
    cin>>n>>k;

    int hi=n, lo=1;
    vector<int> ans;
    for(int i=0; i<n; ++i){
        if((i+1) % k == 0)
            ans.push_back(lo), lo++;
        else
            ans.push_back(hi), hi--;
    }

    for(int i=0; i<n; ++i)
        cout<<ans[i]<<' ';
    cout<<'\n';
}

signed main(){
    int t; cin>>t;
    while(t--) solve();
}