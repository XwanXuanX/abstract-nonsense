#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2510 lang=cpp
 *
 * [2510] Check if There is a Path With Equal Number of 0's And 1's
 */

// @lc code=start
class Solution {
public:
  template <class T> using V = vector<T>;
  bool isThereAPath(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 0)
          grid[i][j] = -1;
      }
    }

    V<V<unordered_set<int>>> dp(n, V<unordered_set<int>>(m));
    dp[0][0].insert(grid[0][0]);
    for (int i = 1; i < n; ++i) {
      for (auto &d : dp[i - 1][0]) {
        dp[i][0].insert(d + grid[i][0]);
      }
    }
    for (int j = 1; j < m; ++j) {
      for (auto &d : dp[0][j - 1]) {
        dp[0][j].insert(d + grid[0][j]);
      }
    }

    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < m; ++j) {
        for (auto &d : dp[i - 1][j]) {
          dp[i][j].insert(d + grid[i][j]);
        }
        for (auto &d : dp[i][j - 1]) {
          dp[i][j].insert(d + grid[i][j]);
        }
      }
    }
    return dp[n - 1][m - 1].contains(0);
  }
};
// @lc code=end
