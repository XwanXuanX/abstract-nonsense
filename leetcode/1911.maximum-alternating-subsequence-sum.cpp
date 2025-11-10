#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1911 lang=cpp
 *
 * [1911] Maximum Alternating Subsequence Sum
 */

// @lc code=start
class Solution {
public:
  template <class T> using V = vector<T>;
  long long maxAlternatingSum(vector<int> &nums) {
    int n = nums.size();
    V<V<long long>> dp(n, V<long long>(2, -2e9));
    dp[0][1] = nums[0];
    for (int i = 1; i < n; ++i) {
      dp[i][1] = nums[i];
      dp[i][0] = max({dp[i][0], 0ll, dp[i - 1][0], dp[i - 1][1] - nums[i]});
      dp[i][1] = max({dp[i][1], 0ll, dp[i - 1][1], dp[i - 1][0] + nums[i]});
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
  }
};
// @lc code=end
