#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    s.insert(s.begin(), '\0');
    t.insert(t.begin(), '\0');
    int n = s.size(), m = t.size();

    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        dp[i][0] = i;
    }
    for (int i = 0; i < m; ++i) {
        dp[0][i] = i;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (s[i] == t[j]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
            }
        }
    }

    cout << dp[n-1][m-1] << '\n';
}