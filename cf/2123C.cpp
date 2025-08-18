#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

void solve() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> perf(n), surf(n);
    perf[0] = a[0], surf[n-1] = a[n-1];
    for (int i = 1; i < n; ++i) {
        perf[i] = min(perf[i-1], a[i]);
    }
    for (int i = n - 2; i >= 0; --i) {
        surf[i] = max(surf[i+1], a[i]);
    }
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] == perf[i] || a[i] == surf[i]) {
            ans[i] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i];
    }
    cout << '\n';
}

// 1. the min and max are 1
// 2. for increasing sequence, only head and tail are 1
// 3. for decreasing sequence, all values are possible

signed main() {
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}