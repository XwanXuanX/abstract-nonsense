#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1060 lang=cpp
 *
 * [1060] Missing Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
  int missingElement(vector<int> &nums, int k) {
    int n = nums.size();
    if (n == 1) {
      return nums.front() + k;
    }
    vector<int> diff;
    for (int i = 1; i < n; ++i) {
      diff.push_back(nums[i] - nums[i - 1] - 1);
    }
    for (int i = 1; i < diff.size(); ++i) {
      diff[i] += diff[i - 1];
    }
    auto lb = lower_bound(diff.begin(), diff.end(), k) - diff.begin();
    if (lb == (int)diff.size()) {
      int left = k - diff.back();
      return nums.back() + left;
    } else if (lb == 0) {
      return nums.front() + k;
    }
    int left = k - diff[lb - 1];
    int base = nums[lb];
    return base + left;
  }
};
// @lc code=end
