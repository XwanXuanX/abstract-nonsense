#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
vector<int> a;

void solve() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // perform exactly once
    int pfs = a[0];
    int ans = __LONG_LONG_MAX__;
    int mn = a[0], mni = 0;
    for (int i = 1; i < n; ++i) {
        if (i - mni > 1) {
            ans = min(ans, pfs);
        } else {
            ans = min(ans, pfs + a[i]);
        }
        if (mn > a[i]) {
            mn = a[i], mni = i;
        }
        pfs += mn;
    }
    // doesn't perform at all
    int tot = a[0], mnn = a[0];
    for (int i = 1; i < n; ++i) {
        mnn = min(mnn, a[i]);
        tot += mnn;
    }
    cout << min(ans, tot) << '\n';
}

// note that the answer is upper bounded by a[0] + a[1]
// you can try to set every position to 0, by doing so,
// you need to add the current position to some value in the front,

signed main() {
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}