#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    if(n==1){
        cout<<0<<endl;
        return;
    }
    
    vector<int> b = a, c = a;
    sort(b.begin(), b.end()); sort(c.begin(), c.end());
    for(int i=1; i<n; ++i)
        c[i] += c[i-1];
    // 20 5 1 4 2
    // 1 2 4 5 20
    // 1 3 7 12 32
    // if we can find if we can go to the next item, then we can partition the array into segments
    // such that all elements in the segment can go to the end
    // 1, 2, 45, 20
    vector<bool> p;
    for(int i=1; i<n; ++i)
        if(c[i-1] >= b[i]) p.push_back(true); else p.push_back(false);
    map<int,int> ans;
    int right=n-1;
    for(int i=n-1; i>=0; --i){
        if(!p[i])
            right = i;
        ans[b[i]] = right;
    }
    ans[b.back()] = n-1;

    for(int i=0; i<n; ++i) cout<<ans[a[i]]<<' ';
    cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}