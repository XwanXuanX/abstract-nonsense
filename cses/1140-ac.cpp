#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<int, int> compress;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        b[i]++;
        compress[a[i]], compress[b[i]];
    }

    int coord = 0;
    for (auto& p : compress) {
        // we assign each day a different value
        // in this way we can make O(1e9) -> O(1e5)
        p.second = coord++;
    }

    // now we need to group projects by their ending date
    vector<vector<pair<int, int>>> proj(coord);
    for (int i = 0; i < n; ++i) {
        proj[compress[b[i]]].push_back(make_pair(compress[a[i]], c[i]));
    }

    vector<ll> dp(coord, 0);
    for (int i = 0; i < coord; ++i) {
        // we can always do nothing and earn the same amount
        if (i >= 1) {
            dp[i] = dp[i - 1];
        }
        // if there are some projects ends on that day
        // we can recalculate the max profit from the ending projects
        for (auto& p : proj[i]) {
            dp[i] = max(dp[i], dp[p.first] + p.second);
        }
    }

    cout << dp[coord - 1] << '\n';
}