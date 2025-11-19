#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2918 lang=cpp
 *
 * [2918] Minimum Equal Sum of Two Arrays After Replacing Zeros
 */

// @lc code=start
class Solution {
public:
  using ll = long long;
  long long minSum(vector<int> &nums1, vector<int> &nums2) {
    ll cnt1 = 0, cnt2 = 0, sum1 = 0, sum2 = 0;
    for (ll n : nums1) {
      if (!n) {
        cnt1++;
      }
      sum1 += n;
    }
    for (ll n : nums2) {
      if (!n) {
        cnt2++;
      }
      sum2 += n;
    }
    // If both arrays have 0, then definitely possible
    ll mn1 = sum1 + cnt1, mn2 = sum2 + cnt2;
    if (cnt1 > 0 && cnt2 > 0) {
      return max(mn1, mn2);
    }
    if (cnt1 == 0 && cnt2 == 0) {
      return (sum1 == sum2) ? sum1 : -1;
    }
    if (cnt1 > 0) {
      return (mn1 > sum2) ? -1 : sum2;
    }
    // if (cnt2 > 0) {
    return (mn2 > sum1) ? -1 : sum1;
    // }
  }
};
// @lc code=end
