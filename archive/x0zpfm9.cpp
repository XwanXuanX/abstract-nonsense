#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,q;
    vector<int> a,x;
    cin>>n>>q;
    a.resize(n);
    x.resize(q);
    for(int i=0; i<n; ++i)
        cin>>a[i];
    for(int i=0; i<q; ++i)
        cin>>x[i];
    int mn=50;
    for(int i=0; i<q; ++i){
        if(x[i]>=mn){
            continue;
        }
        mn=min(mn,x[i]);
        for(int j=0; j<n; ++j){
            int tz=__builtin_ctz(a[j]);
            if(tz<mn)
                continue;
            a[j]|=(1<<(mn-1));
        }
    }
    for(int i=0; i<n; ++i)
        cout<<a[i]<<' ';
    cout<<'\n';
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

// it can be seen that only the strictly decreasing subsequence
// of q will acturally be executed.
// only upto 30 operations, so worst case O(30*n)