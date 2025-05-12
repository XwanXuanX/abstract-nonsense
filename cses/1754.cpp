#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int tt;
    cin >> tt;
    while(tt--) {
        int a, b;
        cin >> a >> b;
        if ((a + b) % 3) {
            cout << "NO\n";
            continue;
        }
        int mn = min(a, b);
        int mx = max(a, b);
        if ((int)ceil((double)mx / 2) > mn) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
}