#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2044 lang=cpp
 *
 * [2044] Count Number of Maximum Bitwise-OR Subsets
 */

// @lc code=start
class Solution {
public:
  int ans = 0;
  int maxOR = 0;

  void backtrack(vector<int>& nums, int i, int orz) {
    if (orz == maxOR) {
      ans++;
    }
    for (int j = i + 1; j < nums.size(); ++j) {
      backtrack(nums, j, orz | nums[j]);
    }
  }

  int countMaxOrSubsets(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      maxOR |= nums[i];
    }
    for (int i = 0; i < n; ++i) {
      backtrack(nums, i, nums[i]);
    }
    return ans;
  }
};
// @lc code=end

