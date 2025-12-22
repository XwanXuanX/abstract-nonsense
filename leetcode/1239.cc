#include <bits/stdc++.h>
using namespace std;

//IMPORTANT!! Submit Code Region Begin(Do not remove this line)
class Solution {
public:
    enum { u, d, l, r };

    static bool check(const int s, const int top, const int bot, const int left, const int right) {
        return top >= s && bot >= s && left >= s && right >= s;
    }

    int largest1BorderedSquare(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(4, 0)));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i][j][l] = !grid[i][j] ? 0 : ((j > 0 ? dp[i][j - 1][l] : 0) + grid[i][j]);
            }
            for (int j = m - 1; j >= 0; --j) {
                dp[i][j][r] = !grid[i][j] ? 0 : ((j < m - 1 ? dp[i][j + 1][r] : 0) + grid[i][j]);
            }
        }
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                dp[i][j][u] = !grid[i][j] ? 0 : ((i > 0 ? dp[i - 1][j][u] : 0) + grid[i][j]);
            }
            for (int i = n - 1; i >= 0; --i) {
                dp[i][j][d] = !grid[i][j] ? 0 : ((i < n - 1 ? dp[i + 1][j][d] : 0) + grid[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int s = 0; i + s < n && j + s < m; ++s) {
                    const int ni = i + s, nj = j + s;
                    const int top = dp[i][j][r], left = dp[i][j][d];
                    const int bot = dp[ni][nj][l], right = dp[ni][nj][u];
                    if (check(s + 1, top, bot, left, right)) {
                        ans = max(ans, (s + 1) * (s + 1));
                    }
                }
            }
        }
        return ans;
    }
};
//IMPORTANT!! Submit Code Region End(Do not remove this line)