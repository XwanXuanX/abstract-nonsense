#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }
    ///
    auto ok = [&](int p) -> bool {
        int tot = 0;
        for (int i=1; i<=a.size(); ++i) {
            if (i == a.size()) {
                tot += p;
                break;
            } else {
                tot += min(p, a[i] - a[i-1]);
            }
        }
        return tot >= h;
    };
    ///
    int l = 0, r = 1e18;
    while (l <= r) {
        int m = (l + r) / 2;
        if (ok(m)) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << l <<'\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}