#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1027 lang=cpp
 *
 * [1027] Longest Arithmetic Subsequence
 */

// @lc code=start
class Solution {
public:
  int longestArithSeqLength(vector<int>& nums) {
    int n = nums.size();
    vector<unordered_map<int,int>> dp(n);
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        int diff = nums[i] - nums[j];
        dp[i][diff] = max(dp[i][diff], dp[j][diff] + 1);
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (auto& p : dp[i]) {
        ans = max(ans, p.second);
      }
    }
    return ans + 1;
  }
};
// @lc code=end

