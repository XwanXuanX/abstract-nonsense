#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1031 lang=cpp
 *
 * [1031] Maximum Sum of Two Non-Overlapping Subarrays
 */

// @lc code=start
class Solution {
public:
  int solve(vector<int> &nums, int firstLen, int secondLen) {
    // Firstlen is Always on the left side of Secondlen
    int n = nums.size();
    int firstSum = 0, secondSum = 0;
    for (int i = 0; i < firstLen; ++i)
      firstSum += nums[i];
    for (int i = firstLen; i < firstLen + secondLen; ++i)
      secondSum += nums[i];
    int secondMax = secondSum;
    int ans = secondMax + firstSum;
    for (int l = firstLen + 1, r = firstLen + secondLen, pl = 1, pr = firstLen;
         r < n; ++r, ++l, ++pl, ++pr) {
      firstSum = firstSum - nums[l - 1] + nums[r];
      secondSum = secondSum - nums[pl - 1] + nums[pr];
      secondMax = max(secondMax, secondSum);
      ans = max(ans, secondMax + firstSum);
    }
    return ans;
  }

  int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
    int n = nums.size();
    return max(solve(nums, firstLen, secondLen),
               solve(nums, secondLen, firstLen));
  }
};
// @lc code=end
