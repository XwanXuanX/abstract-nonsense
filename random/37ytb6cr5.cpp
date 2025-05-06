#include <bits/stdc++.h>
using namespace std;

bool same(vector<int>& a, vector<int>& b){
    for(int i=0; i<a.size(); ++i) if(a[i]!=b[i]) return false;
    return true;
}

void solve(){
    int n; cin>>n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    for(int i=0; i<n; ++i) cin>>b[i];
    bool res=same(a,b);
    reverse(b.begin(), b.end());
    res |= same(a,b);
    if(!res) cout<<"Alice"<<endl;
    else cout<<"Bob"<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}