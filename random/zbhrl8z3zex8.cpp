#include <bits/stdc++.h>
using namespace std;
#define int long long

int calc(int k, int prev, int inc){
    return k*prev + inc;
}

int binary(int prev, int inc, int min){
    int l=0, r=1e9;
    while(l<=r){
        int mid=(l+r)/2;
        if(calc(mid, prev, inc)<=min)
            l=mid+1;
        else
            r=mid-1;
    }
    return l;
}

void solve(){
    int n; cin>>n;
    vector<int> a(n,0);
    for(int i=1; i<n; ++i) cin>>a[i];

    // min of the 1st ele
    a[0] = a[1]+1;

    for(int i=1; i<n-1; ++i)
        a[i]=calc(binary(a[i-1],a[i],a[i+1]) ,a[i-1],a[i]);

    for(int i=0; i<n; ++i) cout<<a[i]<<' ';
    cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}