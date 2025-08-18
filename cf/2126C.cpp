#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> h;

void solve() {
    cin >> n >> k;
    h.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    int ch = h[k - 1];
    sort(h.begin(), h.end());
    int idx = lower_bound(h.begin(), h.end(), ch) - h.begin();
    int water = 1;
    for (int next = idx + 1; next < n; ++next, ++idx) {
        int needtime = h[next] - h[idx];
        if (h[idx] + 1 - water < needtime) {
            cout << "NO\n";
            return;
        }
        water += needtime;
    }
    cout << "YES\n";
}

signed main() {
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}