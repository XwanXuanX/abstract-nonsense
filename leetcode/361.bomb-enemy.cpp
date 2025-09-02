#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=361 lang=cpp
 *
 * [361] Bomb Enemy
 */
/**
 * Try to place the bomb in all empty cells, then we should count the
 * number of people in the same row or column.
 */

// @lc code=start
class Solution {
public:
  int maxKilledEnemies(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 'E') {
          // fill up
          int up = i;
          while (up >= 0 && grid[up][j] != 'W')
            dp[up][j]++, up--;
          // fill down
          int down = i + 1;
          while (down < n && grid[down][j] != 'W')
            dp[down][j]++, down++;
          // fill left
          int left = j;
          while (left >= 0 && grid[i][left] != 'W')
            dp[i][left]++, left--;
          // fill right
          int right = j + 1;
          while (right < m && grid[i][right] != 'W')
            dp[i][right]++, right++;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == '0')
          ans = max(ans, dp[i][j]);
      }
    }
    return ans;
  }
};
// @lc code=end

