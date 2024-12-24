#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<int> a;

void solve(){
    cin>>n>>k;
    k--;
    a.assign(n,0);
    for(int i=0; i<n; ++i)
        cin>>a[i];
    
    // first bigger
    int fb=-1;
    for(int i=0; i<k; ++i)
        if(a[i] > a[k]){
            fb=i;
            break;
        }
    
    int ans=0;
    if(fb!=-1){
        swap(a[fb], a[k]);
        int cnt=0;
        for(int i=fb+1; i<n; ++i){
            if(a[i] > a[fb])
                break;
            cnt++;
        }
        if(fb>0)
            cnt++;
        ans=max(ans, cnt);
        swap(a[fb], a[k]);
    }

    // second move to head
    swap(a[0], a[k]);
    int cnt=0;
    for(int i=1; i<n; ++i){
        if(a[i] > a[0])
            break;
        cnt++;
    }

    cout<<max(ans, cnt)<<'\n';
}

// if there is a bigger cow before kth cow, then win 0 match
// so you either swap with the first bigger cow, which will win at least 1 match
// or you simply swap with the first cow
// there is no point in trying anything else

signed main(){
    int t; cin>>t;
    while(t--) solve();
}