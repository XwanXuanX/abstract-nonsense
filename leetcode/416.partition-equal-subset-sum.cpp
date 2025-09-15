#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
  bool canPartition(vector<int>& nums) {
    // Some prechecks to skip invalid cases fast
    int tot = accumulate(nums.begin(), nums.end(), 0);
    if (tot % 2) return false;
    for (int x : nums)
      if (x > tot / 2) return false;
    // Main DP solu
    int n = nums.size(), m = tot/2 + 1;
    vector<vector<bool>> dp(n, vector<bool>(m));
    dp[0][0] = dp[0][nums[0]] = true;
    for (int i = 0; i < n - 1; ++i) {
      int next = nums[i+1];
      for (int j = 0; j < m; ++j) {
        if (dp[i][j]) {
          dp[i+1][j] = true;
          if (j + next < m) dp[i+1][j+next] = true;
        }
      }
    }
    return dp[n-1][m-1];
  }
};
// @lc code=end

