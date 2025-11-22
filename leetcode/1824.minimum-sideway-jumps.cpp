#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1824 lang=cpp
 *
 * [1824] Minimum Sideway Jumps
 */

// @lc code=start
class Solution {
public:
  template <class T> using V = vector<T>;
  int minSideJumps(vector<int> &obstacles) {
    int n = obstacles.size();
    V<V<int>> dp(n, V<int>(3, 1e9));
    dp[0][1] = 0;
    dp[0][0] = dp[0][2] = 1;
    for (int i = 1; i < n; ++i) {
      int obs = obstacles[i];
      for (int j = 0; j < 3; ++j) {
        if (obs == j + 1) {
          continue;
        }
        // You can try to do forward jump
        dp[i][j] = min(dp[i][j], dp[i - 1][j]);
        for (int k = 0; k < 3; ++k) {
          if (obs == k + 1 || k == j) {
            continue;
          }
          dp[i][j] = min(dp[i][j], dp[i - 1][k] + 1);
        }
      }
    }
    return *min_element(dp[n - 1].begin(), dp[n - 1].end());
  }
};
// @lc code=end
