#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    scanf("%d", &n);
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
        if (n % 2) { // odd length - 1st will take the last
            dp[i][i] = a[i];
        } else { // even length - 2nd will take the last
            dp[i][i] = 0;
        }
    }

    bool isP1 = (n % 2) ? false : true;
    for (int row = 0; row < n; ++row) {
        for (int col = 1; col <= n; ++col) {
            if (row + col > n) {
                break;
            }
            if (isP1) {
                // if it's p1's turn, then we need to calculate the sum
                int i = row + col, j = col;
                if (j - 1 >= 1) {
                    dp[i][j - 1] = max(dp[i][j - 1], dp[i][j] + a[j - 1]);
                }
                if (i + 1 <= n) {
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[i + 1]);
                }
                isP1 = false;
            } else {
                // if it's p2's turn, then we need to minimize the sum
                // by taking minimums
                int i = row + col, j = col;
                if (j - 1 >= 1) {
                    // dp[i][j - 1] = min(dp[i][j - 1], dp[i][j]);
                    dp[i][j - 1] = dp[i][j];
                }
                if (i + 1 <= n) {
                    // dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
                    dp[i + 1][j] = dp[i][j];
                }
                isP1 = true;
            }
        }
    }

    for (int i = 0; i < dp.size(); ++i) {
        for (int j = 0; j < dp[0].size(); ++j) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    printf("%d\n", dp[n][1]);
}