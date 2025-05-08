#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // the state parameters are correct
    // however the state definition is wrong
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int l = n; l >= 1; --l) {
        for (int r = l; r <= n; ++r) {
            if (l == r) {
                // p1 has no other choice
                dp[l][r] = a[l];
            } else {
                // p1 can take either x[l] or x[r]
                // and shrink the boundary
                dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
            }
        }
    }

    int sum = accumulate(a.begin(), a.end(), 0ll);
    cout << (sum + dp[1][n]) / 2 << '\n';
}