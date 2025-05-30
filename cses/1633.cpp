#include <bits/stdc++.h>
using namespace std;
constexpr int mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int gap = 1; gap <= 6; gap++) {
            if (i - gap < 0) {
                break;
            }
            dp[i] = (dp[i] + dp[i-gap]) % mod;
        }
    }
    cout << dp[n] << '\n';
}