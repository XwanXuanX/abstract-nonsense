#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2110 lang=cpp
 *
 * [2110] Number of Smooth Descent Periods of a Stock
 */

// @lc code=start
class Solution {
public:
  long long getDescentPeriods(vector<int>& prices) {
    long long ans = 0;
    long long n = prices.size();
    for (long long l = 0, r = 0; r < n; ++r) {
      if (r + 1 < n && prices[r + 1] + 1 == prices[r]) {
        // We can expand it one more
      } else {
        // We can't expand it, thus record
        long long dist = r - l + 1;
        ans += (dist * (dist + 1)) / 2;
        l = r + 1;
      }
    }
    return ans;
  }
};
// @lc code=end

