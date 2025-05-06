#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x,y,k; cin>>x>>y>>k;
    int mn = min(x,y);
    printf("%d %d %d %d\n%d %d %d %d\n", 0,0,mn,mn,0,mn,mn,0);
}

signed main(){
    int t; cin>>t;
    while(t--) solve();
}