#include <bits/stdc++.h>
using namespace std;
#define int long long

bool ok(int h, vector<int>& a, int x) {
    int tot=0;
    for(int i=0; i<a.size(); ++i) {
        tot += max(0ll, h-a[i]);
    }
    return tot <= x;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n,x;
        cin>>n>>x;
        vector<int> a(n);
        for(int i=0; i<n; ++i) {
            cin>>a[i];
        }

        int ans=0;
        int left=1, right=1e10;
        while(left<=right) {
            int mid = (left+right)/2;
            if(ok(mid, a, x)) {
                ans=max(ans, mid);
                left=mid+1;
            }else{
                right=mid-1;
            }
        }

        cout<<ans<<'\n';
    }
}