#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=562 lang=cpp
 *
 * [562] Longest Line of Consecutive One in Matrix
 */

// @lc code=start
class Solution {
public:
  template <class T> using V = vector<T>;
  int longestLine(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    V<V<V<int>>> dp(n, V<V<int>>(m, V<int>(3, 0)));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mat[i][j]) {
          // Init
          dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = 1;
          // Top
          if (i - 1 >= 0) {
            dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][0] + 1);
          }
          // Left
          if (j - 1 >= 0) {
            dp[i][j][1] = max(dp[i][j][1], dp[i][j-1][1] + 1);
          }
          // Diag
          if (i - 1 >= 0 && j - 1 >= 0) {
            dp[i][j][2] = max(dp[i][j][2], dp[i-1][j-1][2] + 1);
          }
        }
      }
    }
    V<V<int>> dp2(n, V<int>(m, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = m - 1; j >= 0; --j) {
        if (mat[i][j]) {
          dp2[i][j] = 1;
          if (i - 1 >= 0 && j + 1 < m) {
            dp2[i][j] = max(dp2[i][j], dp2[i-1][j+1] + 1);
          }
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        for (int k = 0; k < 3; ++k) {
          ans = max(ans, dp[i][j][k]);
          ans = max(ans, dp2[i][j]);
        }
      }
    }
    return ans;
  }
};
// @lc code=end

