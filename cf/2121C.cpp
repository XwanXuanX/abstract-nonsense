#include <bits/stdc++.h>
#include <utility>
using namespace std;

int n, m;

void solve() {
    cin >> n >> m;
    int mx = 0;
    vector<vector<int>> a(n, vector<int>(m));
    vector<pair<int,int>> mxs;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            mx = max(mx, a[i][j]);
        }
    }
    // try to group points into groups
    // one with the same row, the other with same column
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == mx) {
                mxs.push_back({i, j});
            }
        }
    }
    auto ok = [&](int r = -1, int c = -1) {
        int r_fixed = r != -1, c_fixed = c != -1;
        for (auto [i, j] : mxs) {
            if (r_fixed && r == i || c_fixed && c == j) {
                continue;
            }
            if (r_fixed && !c_fixed) {
                c = j, c_fixed = true;
            } else if (c_fixed && !r_fixed) {
                r = i, r_fixed = true;
            } else {
                return false;
            }
        }
        return true;
    };
    if (ok(mxs[0].first, -1) || ok(-1, mxs[0].second)) {
        cout << mx - 1 << '\n';
    } else {
        cout << mx << '\n';
    }
}

signed main() {
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}