#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> a(n, vector<int>(m));
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                cin>>a[i][j];
            }
        }
        vector<pair<int,int>> idx;
        for(int i=0; i<n; ++i) {
            int sum = accumulate(a[i].begin(), a[i].end(), 0);
            idx.push_back(make_pair(sum, i));
        }
        sort(idx.rbegin(), idx.rend());

        vector<int> res;
        for(int i=0; i<n; ++i) {
            int pos = idx[i].second;
            for(int j=0; j<m; ++j) {
                res.push_back(a[pos][j]);
            }
        }
        for(int i=1; i<res.size(); ++i) {
            res[i] += res[i-1];
        }

        int ans=0;
        for(int i=0; i<res.size(); ++i) {
            ans += res[i];
        }
        cout<<ans<<'\n';
    }
}