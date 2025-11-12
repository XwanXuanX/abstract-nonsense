#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int cost(int n) { return n == 0 ? 0 : 1; }

  template <class T> using V = vector<T>;
  int maxPathScore(vector<vector<int>> &grid, int k) {
    int n = grid.size(), m = grid[0].size();
    V<V<V<int>>> dp(n, V<V<int>>(m, V<int>(k + 1, INT_MIN)));
    for (int o = 0; o <= k; ++o) {
      dp[0][0][o] = 0;
    }
    for (int j = 1; j < m; ++j) {
      for (int o = 0; o <= k; ++o) {
        if (o - cost(grid[0][j]) >= 0 &&
            dp[0][j - 1][o - cost(grid[0][j])] != INT_MIN)
          dp[0][j][o] =
              max(dp[0][j][o], dp[0][j - 1][o - cost(grid[0][j])] + grid[0][j]);
      }
    }
    for (int i = 1; i < n; ++i) {
      for (int o = 0; o <= k; ++o) {
        if (o - cost(grid[i][0]) >= 0 &&
            dp[i - 1][0][o - cost(grid[i][0])] != INT_MIN)
          dp[i][0][o] =
              max(dp[i][0][o], dp[i - 1][0][o - cost(grid[i][0])] + grid[i][0]);
      }
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < m; ++j) {
        for (int o = 0; o <= k; ++o) {
          int remain = o - cost(grid[i][j]);
          if (remain < 0) {
            continue;
          }
          if (dp[i - 1][j][remain] != INT_MIN) {
            dp[i][j][o] = max(dp[i][j][o], dp[i - 1][j][remain] + grid[i][j]);
          }
          if (dp[i][j - 1][remain] != INT_MIN) {
            dp[i][j][o] = max(dp[i][j][o], dp[i][j - 1][remain] + grid[i][j]);
          }
        }
      }
    }
    int ans = INT_MIN;
    for (int o = 0; o <= k; ++o) {
      ans = max(ans, dp[n - 1][m - 1][o]);
    }
    if (ans == INT_MIN) {
      return -1;
    }
    return ans;
  }
};