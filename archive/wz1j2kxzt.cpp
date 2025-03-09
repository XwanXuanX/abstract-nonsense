#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n, m;
        cin>>n>>m;
        vector<int> a(n), b(m);
        for(int i=0; i<n; ++i) {
            cin>>a[i];
        }
        for(int i=0; i<m; ++i) {
            cin>>b[i];
        }

        // for bs
        sort(b.begin(), b.end());

        int ok=1, prev=a[0];
        for (int i=0; i<m; ++i) {
            prev=min(prev, b[i]-a[0]);
        }
        for (int i=1; i<n; ++i) {
            // b[j] >= prev + a[i]
            auto it = lower_bound(b.begin(), b.end(), prev+a[i]);
            if (it==b.end() && a[i]<prev) {
                ok &= 0;
                break;
            }
            if (it != b.end() && a[i] >= prev) {
                prev = min(a[i], *it-a[i]);
            } else if(it == b.end()) {
                prev = a[i];
            } else {
                prev = *it-a[i];
            }
        }

        if (ok) {
            cout<<"YES\n";
        } else  {
            cout<<"NO\n";
        }
    }
}