#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=276 lang=cpp
 *
 * [276] Paint Fence
 */

/**
 * let dp[i][j] be the number of ways to paint the ith fence with
 * color j. then fence (i-1) and (i-2) can be j.
 * dp[i][j] = dp[i-1][k] for all k != j + dp[i-2][k] for all k != j
 */

// @lc code=start
class Solution {
public:
  int numWays(int n, int k) {
    vector<vector<int>> dp(n, vector<int>(k, 0));
    for (int i = 0; i < k; ++i)
      dp[0][i] = 1;
    for (int i = 1; i < n; ++i) {
      int sum1 = 0, sum2 = 0;
      if (i - 1 >= 0)
        sum1 = accumulate(dp[i-1].begin(), dp[i-1].end(), 0);
      if (i - 2 >= 0)
        sum2 = accumulate(dp[i-2].begin(), dp[i-2].end(), 0);
      for (int j = 0; j < k; ++j) {
        if (i == 1) {
          dp[i][j] += sum1;
        } else {
          // fence i different from the previous fence
          if (i - 1 >= 0)
            dp[i][j] += sum1 - dp[i-1][j];
          // fence i different from the 2nd previous fence
          if (i - 2 >= 0)
            dp[i][j] += sum2 - dp[i-2][j];
        }
      }
    }
    return accumulate(dp[n-1].begin(), dp[n-1].end(), 0);
  }
};
// @lc code=end

