#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=3190 lang=cpp
 *
 * [3190] Find Minimum Operations to Make All Elements Divisible by Three
 */

// @lc code=start
class Solution {
public:
  int minimumOperations(vector<int> &nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int diff = INT_MAX;
      for (int j = 0; j <= 60; j += 3) {
        diff = min(diff, abs(nums[i] - j));
      }
      ans += diff;
    }
    return ans;
  }
};
// @lc code=end
