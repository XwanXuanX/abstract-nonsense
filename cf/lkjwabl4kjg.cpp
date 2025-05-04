#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m;
    scanf("%lld %lld", &n, &m);
    vector<int> sum(n,0);
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j){
            scanf("%lld", &mat[i][j]);
            sum[i] += mat[i][j];
        }
    
    int tot=accumulate(sum.begin(),sum.end(),0ll);
    if(tot%n){
        puts("-1");
        return;
    }

    // each row should `ntains exactly this amount of 1s
    int target = tot / n;

    vector<tuple<int,int,int>> ans;
    vector<int> vg, vl;
    for(int j=0;j<m;++j){
        for(int i=0;i<n;++i){
            if(sum[i] > target && mat[i][j])
                vg.push_back(i);
            if(sum[i] < target && !mat[i][j])
                vl.push_back(i);
        }
        for(int i=0;i<min(vg.size(),vl.size());++i){
            ++sum[vl[i]], --sum[vg[i]];
            ans.push_back(make_tuple(vl[i], vg[i], j));
        }
        vg.clear(), vl.clear();
    }

    printf("%lld\n", ans.size());
    for(auto[x, y, p]:ans)
        printf("%lld %lld %lld\n", x+1, y+1, p+1);
    return;
}

signed main(){
    int t;
    scanf("%lld", &t);
    while(t--)
        solve();
}