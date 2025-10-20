#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
  int rob1(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
      return nums[0];
    }
    vector<int> dp(n, 0);
    dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; ++i) {
      dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    return dp[n-1];
  }

  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
      return nums[0];
    }
    // Do two classic house rob
    vector<int> ft(nums.begin() + 1, nums.end());
    vector<int> ed(nums.begin(), nums.end() - 1);
    return max(rob1(ft), rob1(ed));
  }
};
// @lc code=end

