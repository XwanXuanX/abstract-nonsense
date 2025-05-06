#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    for (int i = 0; i < n; ++i) {
        dp[i][0] = 1;
    }
    for (int sum = 1; sum <= x; ++sum) {
        for (int i = 0; i < n; ++i) {
            if (i - 1 >= 0) {
                dp[i][sum] = (dp[i][sum] + dp[i-1][sum]) % mod;
            }
            if (sum - a[i] >= 0) {
                dp[i][sum] = (dp[i][sum] + dp[i][sum - a[i]]) % mod;
            }
        }
    }
    cout << dp[n-1][x] << '\n';
}
