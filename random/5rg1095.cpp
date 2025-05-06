#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
const int INF=1e9;

void solve(){
    cin>>n;
    a.assign(n,0);
    for(int i=0; i<n; ++i)
        cin>>a[i];

    int ans=INF;
    for(int i=0; i<n; ++i){
        int tot=i;
        for(int j=i+1; j<n; ++j)
            if(a[j] > a[i])
                tot++;
        ans=min(ans, tot);
    }

    cout<<ans<<'\n';
}

// we want to have just one element left
// if we made the center to be any element, then we have to remove the ones that are smaller on the left
// and the ones that are (strictly) larger on the right

signed main(){
    int t; cin>>t;
    while(t--) solve();
}