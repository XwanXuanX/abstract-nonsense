#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod=1e9+7;

void solve(){
    int n;
    vector<int> a,b;
    cin>>n;
    a.resize(n);
    b.resize(n);
    for(int i=0; i<n; ++i)
        cin>>a[i];
    for(int i=0; i<n; ++i)
        cin>>b[i];
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    vector<int> up(n);
    for(int i=0; i<n; ++i){
        int idx=(int)(upper_bound(a.begin(),a.end(),b[i])-a.begin());
        up[i]=n-idx;
    }
    int ans=1;
    for(int i=0; i<n; ++i){
        if(up[i]-i<=0){
            cout<<0<<'\n';
            return;
        }
        ans=(ans%mod * (up[i]-i)%mod) %mod;
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

// 9 6 8 4 5 2
// 4 1 5 6 3 1
// 6: 8 9 - 2
// 5: 6 8 9 - 2
// 4: 5 6 8 9 - 2
// 3: 4 5 6 8 9 - 2
// 1: 2 4 5 6 8 9 - 2
// 1: 2 4 5 6 8 9 - 1
// so ans = 2^5 x1 = 32