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
        for(int i=0; i<n; ++i) {
            cin>>a[i];
        }
        // YES iff you can sort with pair-wise swap
        for(int i=n-1; i>= 1; i-=2) {
            if(a[i] < a[i-1]) {
                swap(a[i], a[i-1]);
            }
        }
        if(is_sorted(a.begin(), a.end())) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }
}