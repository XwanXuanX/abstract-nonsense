#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        vector<int> a(n);
        for (int i=0; i<n; ++i) {
            cin>>a[i];
        }
        int cnt=0;
        for (int i=0; i<n; ++i) {
            // left
            int dl=i * 2;
            int dr=((n-1)-i) * 2;
            if (dl>=a[i] || dr>=a[i]) {
                cnt++;
            }
        }
        if (cnt==0) {
            cout<<"YES\n";
        } else  {
            cout<<"NO\n";
        }
    }
}