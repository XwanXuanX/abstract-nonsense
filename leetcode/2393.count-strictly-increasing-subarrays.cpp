#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2393 lang=cpp
 *
 * [2393] Count Strictly Increasing Subarrays
 */

// @lc code=start
class Solution {
public:
  using ll = long long;
  long long countSubarrays(vector<int> &nums) {
    ll n = nums.size();
    vector<pair<ll, ll>> seg;
    ll start = 0;
    for (ll i = 1; i < n; ++i) {
      if (nums[i] <= nums[i - 1]) {
        seg.emplace_back(start, i - 1);
        start = i;
      }
    }
    seg.emplace_back(start, n - 1);
    ll ans = 0;
    for (auto &p : seg) {
      ll len = p.second - p.first + 1;
      ans += ((len + 1) * len) / 2;
    }
    return ans;
  }
};
// @lc code=end
