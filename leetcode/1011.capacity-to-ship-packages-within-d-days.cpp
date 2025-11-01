#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
class Solution {
public:
  bool ok(vector<int>& weights, int cap, int days) {
    int need = 0, idx = 0, current = 0;
    while (idx < weights.size()) {
      if (current + weights[idx] > cap) {
        need++;
        current = 0;
      }
      current += weights[idx];
      idx++;
    }
    return need + 1 <= days;
  }

  int shipWithinDays(vector<int>& weights, int days) {
    int tot = accumulate(weights.begin(), weights.end(), 0);
    int mn = *max_element(weights.begin(), weights.end());
    int l = mn, r = tot, ans = INT_MAX;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (ok(weights, mid, days)) {
        ans = min(ans, mid);
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return ans;
  }
};
// @lc code=end

