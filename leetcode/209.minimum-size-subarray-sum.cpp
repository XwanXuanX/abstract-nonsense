#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int ans = INT_MAX;
    int sum = 0;
    for (int l = 0, r = 0; r < n; ++r) {
      sum += nums[r];
      while (l < r && sum > target) {
        if (sum - nums[l] < target) {
          break;
        }
        sum -= nums[l];
        l++;
      }
      if (sum >= target) {
        ans = min(ans, r - l + 1);
      }
    }
    if (ans == INT_MAX) {
      return 0;
    }
    return ans;
  }
};
// @lc code=end

