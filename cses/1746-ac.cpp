#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    if (a[1] != 0) {
        dp[1][a[1]] = 1;
    } else {
        for (int i = 1; i <= m; ++i) {
            dp[1][i] = 1;
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (!a[i]) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
                if (j - 1 >= 1) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
                }
                if (j + 1 <= m) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % mod;
                }            
            }
        } else {
            int j = a[i];
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
            if (j - 1 >= 1) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
            }
            if (j + 1 <= m) {
                dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % mod;
            }            
        }      
    }

    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        ans = (ans + dp[n][i]) % mod;
    }
    printf("%d\n", ans);
}