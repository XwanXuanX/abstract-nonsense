#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    scanf("%d %d", &a, &b);

    vector<vector<int>> dp(a + 1, vector<int>(b + 1, INT_MAX));
    for (int i = 1; i <= a; ++i) {
        dp[i][1] = i - 1;
    }
    for (int i = 1; i <= b; ++i) {
        dp[1][i] = i - 1;
    }
    for (int i = 1; i <= min(a, b); ++i) {
        dp[i][i] = 0;
    }

    for (int i = 2; i <= a; ++i) {
        for (int j = 2; j <= b; ++j) {
            for (int v = 1; v <= i/2; ++v) {
                dp[i][j] = min(dp[i][j], dp[v][j] + dp[i-v][j] + 1);
            }
            for (int h = 1; h <= j/2; ++h) {
                dp[i][j] = min(dp[i][j], dp[i][h] + dp[i][j-h] + 1);
            }
        }
    }

    cout << dp[a][b] << '\n';
}