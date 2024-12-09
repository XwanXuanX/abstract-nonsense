#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<vector<int>> a(n, vector<int>(n,0));
    for(int i=0; i<n; ++i) for(int j=0; j<n; ++j) cin>>a[i][j];
    int ans=0;
    for(int i=1; i<n; ++i){
        int topmn=0, botmn=0;
        for(int j=0; i+j<n; ++j){
            topmn=min(topmn, a[j][i+j]);
            botmn=min(botmn, a[i+j][j]);
        }
        ans+=(topmn+botmn);
    }
    int mid=0;
    for(int i=0; i<n; ++i) mid=min(mid, a[i][i]);
    cout<<abs(ans+mid)<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}