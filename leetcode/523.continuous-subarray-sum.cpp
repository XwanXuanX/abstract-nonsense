#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> pfs(n, 0);
    pfs[0] = nums[0] % k;
    for (int i = 1; i < n; ++i) {
      pfs[i] = pfs[i-1] + nums[i];
      pfs[i] %= k;
    }
    set<int> s;
    s.insert(0);
    for (int i = 1; i < n; ++i) {
      if (s.count(pfs[i])) {
        return true;
      }
      s.insert(pfs[i-1]);
    }
    return false;
  }
};
// @lc code=end

