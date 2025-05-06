#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n; scanf("%lld", &n);
    vector<int> a(n);
    for(int i=0; i<n; ++i) scanf("%lld", &a[i]);
    
    if(n<3){
        printf("0\n");
        return;
    }

    int start=1;
    sort(a.begin(), a.end());
    vector<pair<int,int>> seg;

    for(int i=2; i<n; ++i)
        if(a[i]!=a[i-1]){
            if(i-start > 1)
                seg.push_back(make_pair(start, i-1));
            start=i;
        }
    if(n-start > 1)
        seg.push_back(make_pair(start, n-1));

    int ans=0;
    for(auto& p:seg)
        for(int i=p.first; i<p.second; ++i)
            ans += (i * (p.second - i));

    printf("%lld\n", ans);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; scanf("%lld", &t);
    while(t--) solve();
}