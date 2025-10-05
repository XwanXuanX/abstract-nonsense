#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
  int binarySearch(vector<int>& nums, int start, int target) {
    int l = start, r = nums.size() - 1;
    int ans = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (nums[mid] > target) {
        r = mid - 1;
      } else {
        ans = max(ans, mid);
        l = mid + 1;
      }
    }
    return ans;
  }
  
  int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    int ans = 0, initialized = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; ++i) {
      for (int j = i + 1; j < n - 1; ++j) {
        int other = target - nums[i] - nums[j];
        // now we just need to find the closest numebr to other
        // from [j + 1, n - 1]
        int closer = 0;
        int k = binarySearch(nums, j + 1, other);
        if (k == -1) {
          closer = nums[j + 1];
        } else {
          closer = nums[k];
          if (k + 1 < n && abs(nums[k+1] - other) < abs(nums[k] - other)) {
            closer = nums[k+1];
          }
        }
        int nn = nums[i] + nums[j] + closer;
        if (initialized) {
          if (abs(ans - target) > abs(nn - target)) {
            ans = nn;
          }
        } else {
          ans = nn;
          initialized = true;
        }
      }
    }
    return ans;
  }
};
// @lc code=end

