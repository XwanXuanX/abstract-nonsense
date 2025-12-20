#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int> &colors, vector<vector<int> > &queries) {
        const int n = colors.size();
        for (int &c: colors) {
            c = c - 1;
        }
        vector<vector<int> > dp(3, vector<int>(n, 1e9));
        for (int i = 0; i < 3; ++i) {
            dp[i][0] = colors[0] == i ? 0 : 1e9;
            for (int j = 1; j < n; ++j) {
                dp[i][j] = colors[j] == i ? 0 : min(dp[i][j - 1] + 1, dp[i][j]);
            }
            dp[i][n - 1] = colors[n - 1] == i ? 0 : min(dp[i][n - 1], static_cast<int>(1e9));
            for (int j = n - 2; j >= 0; --j) {
                dp[i][j] = colors[j] == i ? 0 : min(dp[i][j + 1] + 1, dp[i][j]);
            }
        }
        vector<int> ans;
        for (const auto &q: queries) {
            const int i = q[0], c = q[1];
            ans.push_back(dp[c - 1][i] == 1e9 ? -1 : dp[c - 1][i]);
        }
        return ans;
    }
};

//IMPORTANT!! Submit Code Region End(Do not remove this line)
