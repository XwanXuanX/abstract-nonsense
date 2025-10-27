#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2771 lang=cpp
 *
 * [2771] Longest Non-decreasing Subarray From Two Arrays
 */

// @lc code=start
class Solution {
public:
  int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<vector<int>> dp(n, vector<int>(2, 1));
    for (int i = 1; i < n; ++i) {
      // First try to pick from the first array
      {
        if (nums1[i] >= nums1[i-1]) dp[i][0] = max(dp[i][0], dp[i-1][0] + 1);
        if (nums1[i] >= nums2[i-1]) dp[i][0] = max(dp[i][0], dp[i-1][1] + 1);
      }
      // Then try to pick from the second array
      {
        if (nums2[i] >= nums1[i-1]) dp[i][1] = max(dp[i][1], dp[i-1][0] + 1);
        if (nums2[i] >= nums2[i-1]) dp[i][1] = max(dp[i][1], dp[i-1][1] + 1);
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    return ans;
  }
};
// @lc code=end

