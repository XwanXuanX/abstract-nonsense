#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i=1; i<=n; ++i) cin>>a[i];
    for(int i=2; i<=(int)ceil((double)n/2); ++i)
        if(a[i] != a[n-i+1])
            if(a[i] == a[i-1] || a[n-i+1] == a[n-i+2])
                swap(a[i], a[n-i+1]);
    int ans=0;
    for(int i=2; i<=n; ++i)
        if(a[i] == a[i-1]) ans++;
    cout<<ans<<endl;
}

// for any i == i+1, we can perform the swap
// 3 1 3 2 2 3 3
// 3 3 3 2 2 1 3
// 3 3 2 2 3 1 3
// 1 2 1 ... 3 1 1 = 1
// the claim is: whenever there is i==i+1, then we swap i+1. this is always better since
// if right side same, no effect; if right side different, then -1 and 

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}