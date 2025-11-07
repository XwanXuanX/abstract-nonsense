/*
 * @lc app=leetcode id=1015 lang=cpp
 *
 * [1015] Smallest Integer Divisible by K
 */

// @lc code=start
class Solution {
public:
  int smallestRepunitDivByK(int k) {
    int rem = 0;
    for (int len = 1; len <= k; ++len) {
      rem = ((rem * 10) + 1) % k;
      if (rem == 0) {
        return len;
      }
    }
    return -1;
  }
};
// @lc code=end

