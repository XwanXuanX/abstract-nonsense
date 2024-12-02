#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin>>a[i];
    auto mir = [&](int i)->int{ return n - i - 1; };
    map<int,int> cnt;
    for(int i=0; i<n/2; ++i){
        int j = mir(i);
        a[i] -= (i+1); a[j] -= (i+1);
        cnt[a[i]]++; cnt[a[j]]++;
    }
    if(n % 2){
        a[n/2] -= (n/2 + 1);
        cnt[a[n/2]]++;
    }
    int mx=0, offset=0;
    for(auto& p:cnt)
        if(p.first >= 0 && p.second > mx){
            mx = p.second;
            offset = p.first;
        }
    int ans=0;
    for(int i=0; i<n; ++i)
        if(a[i] != offset) ans++;
    cout<<ans<<endl;
    return 0;
}