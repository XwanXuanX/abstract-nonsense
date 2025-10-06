#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
class Solution {
public:
  int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    int tot = accumulate(nums.begin(), nums.end(), 0);
    int pref = 0;
    for (int i = 0; i < n; ++i) {
      tot -= nums[i];
      if (pref == tot) {
        return i;
      }
      pref += nums[i];
    }
    return -1;
  }
};
// @lc code=end

