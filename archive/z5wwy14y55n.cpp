#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n,m;
        cin>>n>>m;
        vector<int> a(n);
        int b;
        for (int i=0; i<n; ++i) {
            cin>>a[i];
        }
        cin>>b;

        vector<int> c;
        for (int i=0; i<n; ++i) {
            c.push_back(b-a[i]);
        }
        int ok=1, prev=min(a[0], c[0]);
        for (int i=1; i<n; ++i) {
            if (max(a[i], c[i]) < prev) {
                ok &= 0;
                break;
            }
            if (a[i] >= prev && c[i] >= prev) {
                prev = min(a[i], c[i]);
            } else if (a[i] >= prev) {
                prev = a[i];
            } else {
                prev = c[i];
            }
        }
        if (ok) {
            cout<<"YES\n";
        } else  {
            cout<<"NO\n";
        }
    }
}