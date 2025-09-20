#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
class Solution {
public:
  int nthUglyNumber(int n) {
    vector<int> nums(n);
    nums[0] = 1;
    int i2 = 0, i3 = 0, i5 = 0;
    int n2 = 2, n3 = 3, n5 = 5;
    for (int i = 1; i < n; ++i) {
      int nt = min({n2, n3, n5});
      nums[i] = nt;
      if (nt == n2) i2++, n2 = nums[i2] * 2;
      if (nt == n3) i3++, n3 = nums[i3] * 3;
      if (nt == n5) i5++, n5 = nums[i5] * 5;
    }
    return nums[n-1];
  }
};
// @lc code=end

