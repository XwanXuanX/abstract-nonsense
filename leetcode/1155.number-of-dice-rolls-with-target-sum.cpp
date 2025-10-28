#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1155 lang=cpp
 *
 * [1155] Number of Dice Rolls With Target Sum
 */

// @lc code=start
class Solution {
public:
  const int mod = 1e9 + 7;

  int numRollsToTarget(int n, int k, int target) {
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    for (int i = 1; i <= min(k, target); ++i) {
      dp[0][i] = 1;
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j <= target; ++j) {
        dp[i][j] = 0;
        for (int o = 1; o <= k; ++o) {
          if (j - o >= 0)
            dp[i][j] = (dp[i][j] + dp[i - 1][j - o]) % mod;
        }
      }
    }
    return dp[n - 1][target];
  }
};
// @lc code=end
