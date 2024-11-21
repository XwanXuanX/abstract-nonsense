#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m,k; cin>>n>>m>>k;
    int diag = min(n, m), straight = max(n, m) - diag, mp = diag + straight;
    if(k < mp){ cout<<-1<<endl; return; }
    int ans = diag, exc = k - mp;
    if(straight % 2 == 0){
        if(exc % 2 == 0) ans += (exc + straight);
        else ans += ((straight - 1) + (exc / 2) * 2);
    }else{
        if(exc % 2 == 0) ans += ((straight - 1) + exc);
        else ans += (straight + (exc / 2) * 2);
    }
    cout<<ans<<endl;
}

/**
 * it can be observed that if k + 2 or k + 1 can all be resolved by adding additional steps
 * so proved that if k >= minimum distance required, there is a path to reach target
 * now how to get maximum diag paths: we move in diagnal if needed, and zigzag the hor/ver part
 */

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}