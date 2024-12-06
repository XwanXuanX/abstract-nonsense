#include <bits/stdc++.h>
using namespace  std;

void solve(){
    int n; cin>>n;
    vector<int> a(n), b(n);
    for(int i=0; i<n; ++i)
        cin>>a[i];
    for(int i=0; i<n; ++i)
        cin>>b[i];

    int ans=0;
    for(int i=0; i<n; ++i){
        if(a[i] > b[i])
            ans += a[i];
        else
            ans += b[i];
    }

    // then you need to choose a path to go from first row to second row
    int better=INT_MIN;
    for(int i=0; i<n; ++i){
        if(a[i] > b[i])
            better = max(better, ans + b[i]);
        else
            better = max(better, ans + a[i]);
    }

    cout<<better<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}