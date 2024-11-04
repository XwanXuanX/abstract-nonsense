#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
    int n,m,k,w;
    cin>>n>>m>>k>>w;
    vector<int> buf(w);
    for(int i=0;i<w;++i)
        cin>>buf[i];
    sort(buf.begin(), buf.end(), greater<int>());

    vector<int> it;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            it.push_back((min(i,n-k) - max((int)-1,i-k)) * (min(j,m-k) - max((int)-1,j-k)));
    sort(it.begin(), it.end(), greater<int>());

    int ans=0;
    for(int i=0;i<buf.size();++i)
        ans += (buf[i] * it[i]);
    
    cout<<ans<<endl;
    return;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}

/**
 * it's obvious that some cells will be sumed up multiple times, and it's optimal to place high in the multiple cells
 * we need to find the number of cells that will be summed multiple times
 */