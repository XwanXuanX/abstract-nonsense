#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=259 lang=cpp
 *
 * [259] 3Sum Smaller
 */

// @lc code=start
class Solution {
public:
  int lowerBound(vector<int>& nums, int start, int target) {
    int left = start, right = nums.size() - 1;
    int ans = 0;
    while (left <= right) {
      int mid = (left + right) >> 1;
      if (nums[mid] >= target) {
        right = mid - 1;
      } else {
        ans = max(ans, mid);
        left = mid + 1;
      }
    }
    return max(ans, right);
  }

  int threeSumSmaller(vector<int>& nums, int target) {
    if (nums.size() < 3) return 0;
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0; i < nums.size() - 2; ++i) {
      for (int j = i + 1; j < nums.size() - 1; ++j) {
        int k = lowerBound(nums, j + 1, target - nums[i] - nums[j]);
        ans += k - j;
      }
    }
    return ans;
  }
};
// @lc code=end

