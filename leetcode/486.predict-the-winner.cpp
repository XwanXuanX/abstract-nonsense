#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */

// @lc code=start
class Solution {
public:
  bool predictTheWinner(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // Base case
    for (int i = 0; i < n; ++i)
      dp[i][i] = nums[i];
    // Iterate over all subproblems
    for (int len = 2; len <= n; ++len) {
      for (int i = 0; i < n - len + 1; ++i) {
        int j = i + len - 1;
        dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
      }
    }
    return dp[0][n-1] >= 0;
  }
};
// @lc code=end

