#include <bits/stdc++.h>
using namespace std;
#define int long long

void printDp(vector<vector<int>>& dp) {
    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < dp[0].size(); ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> k(n+1);
    vector<int> c(m+1);
    for (int i = 1; i <= n;  ++i) {
        cin >> k[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> c[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
    // 0 = give money
    // 1 - m = give gifts
    /// initialize
    for (int i = 0; i <= m; ++i) {
        if (i == 0) {
            dp[1][i] = c[k[1]];
        } else {
            if (i > k[1]) {
                break;
            } else {
                dp[1][i] = c[i];
            }
        }
    }

    printDp(dp);

    /// propogate
    for (int j = 2; j <= n; ++j) {
        for (int i = 0; i <= m; ++i) {
            if (i == 0) {
                int mn = INT_MAX;
                for (int h = 0; h <= m; ++h) {
                    mn = min(mn, dp[j-1][h]);
                }
                dp[j][i] = mn + c[k[j]];
            } else {
                if (i > k[j]) {
                    break;
                } else {
                    int mn = INT_MAX;
                    for (int h = 0; h <= m; ++h) {
                        if (h == i) {
                            continue;
                        }
                        mn = min(mn, dp[j-1][h]);
                    }
                    dp[j][i] = mn + c[i];
                }
            }
        }
    }

    printDp(dp);

    /// collect results
    int ans = INT_MAX;
    for (int i = 0; i <= m; ++i) {
        ans = min(ans, dp[n][i]);
    }
    cout << ans << '\n';

    /// oh wait, this is false! since i'm not restricting each present can at most be bought once!
    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
}