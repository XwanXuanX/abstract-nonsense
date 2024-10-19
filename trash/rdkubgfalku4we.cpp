/**
 * given two names,
 * AAB
 * BAA
 * 1. it's possible to make any two characters exchange their position.
 * we can do 100*100*100 = O(n^3) time
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long

constexpr int MOD=1000000007ll;

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    vector<string> names;
    string name;
    for(int i=0;i<n;++i){
        cin>>name;
        names.push_back(name);
    }

    // count the number of different characters in each column and multiply them together
    vector<int> diff;
    for(int i=0;i<m;++i){
        set<int> cnt;
        for(int j=0;j<n;++j)
            cnt.insert(names[j][i]);
        diff.push_back(cnt.size());
    }

    int ans=1ll;
    for(int i=0;i<diff.size();++i){
        ans=(ans%MOD * diff[i]%MOD) % MOD;
    }

    cout<<ans<<endl;
    return 0;
}
