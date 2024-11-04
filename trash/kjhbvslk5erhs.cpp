#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    sort(a.begin(), a.end());

    bool all_same=true;
    for(int i=1;i<a.size();++i)
        if(a[i]!=a[i-1]){
            all_same=false;
            break;
        }
    
    if(all_same){
        cout<<n/2<<endl;
        return;
    }

    vector<pair<int,int>> segment;
    int start=0;
    for(int i=1;i<a.size();++i)
        if(a[i]!=a[i-1])
            segment.push_back(make_pair(start, i-1)), start=i;
    segment.push_back(make_pair(start, a.size()-1));

    int ans=LLONG_MIN;
    for(int i=0;i<segment.size();++i){
        int before = segment[i].second + 1, after = a.size() - segment[i].second - 1;
        ans = max(ans, before * after);
    }

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
 * if a node connects with nodes above it, then it cannot be connect to nodes below it
 */