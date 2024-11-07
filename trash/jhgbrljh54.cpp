#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(m);
    for(int i=0;i<m;++i)
        cin>>a[i];

    int segment = (n%k==0) ? n/k : n/k + 1;
    int mx=0, cnt=0;
    for(int i=0;i<a.size();++i){
        mx=max(mx,a[i]);
        if(a[i] == segment)
            cnt++;
    }

    if(mx > segment){
        cout<<"NO"<<endl;
        return;
    }

    if(n%k && cnt > n%k){
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
    return;
}

/**
 * it's more optimal to use the color that occur the most time
 * if a color appear more than n/k + 1 times, then definitely not ok
 * else, each color will appear AT MOST once in each cell.
 */

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}