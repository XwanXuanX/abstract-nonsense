#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    vector<pair<int,int>> a;
    cin>>n;
    a.resize(n-1);
    for(int i=0; i<n-1; ++i){
        cin>>a[i].first>>a[i].second;
        a[i].first--;
        a[i].second--;
    }
    vector<int> d(n,0);
    for(int i=0; i<n-1; ++i){
        d[a[i].first]++;
        d[a[i].second]++;
    }
    int nl=0;
    for(int i=0; i<n; ++i){
        if(d[i]==1)
            nl++;
    }
    if(nl%2==0)
        cout<<nl/2<<'\n';
    else
        cout<<(nl-1)/2+1<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }
}

// if we can make all nodes degree 1 and 2
// then we can compress all nodes in one move