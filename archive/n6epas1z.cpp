#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,in; scanf("%d", &n);
    map<int,int> cnt;
    for(int i=0; i<n; ++i) scanf("%d", &in), cnt[in]++;
    vector<int> can;
    for(auto& p:cnt)
        for(int i=0; i<p.second/2; ++i)
            can.push_back(p.first);
    if(can.size() < 4){
        printf("NO\n");
        return;
    }
    printf("YES\n");
    sort(can.begin(), can.end());
    int l = can.size()-1;
    printf("%d %d %d %d %d %d %d %d\n", can[0],can[1],can[0],can[l],can[l-1],can[1],can[l-1],can[l]);
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; scanf("%d", &t);
    while(t--) solve();
}