#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=750 lang=cpp
 *
 * [750] Number Of Corner Rectangles
 */

// @lc code=start
class Solution {
public:
  int countCornerRectangles(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(m, 0));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        for (int k = j + 1; k < m; ++k) {
          if (grid[i][j] && grid[i][k]) {
            ans += dp[j][k];
            dp[j][k]++;
          }
        }
      }
    }
    return ans;
  }
};
// @lc code=end

