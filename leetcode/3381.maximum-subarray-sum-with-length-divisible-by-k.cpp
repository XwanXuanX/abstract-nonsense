#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=3381 lang=cpp
 *
 * [3381] Maximum Subarray Sum With Length Divisible by K
 */

// @lc code=start
class Solution {
public:
  using ll = long long;
  template <class T> using V = vector<T>;
  long long maxSubarraySum(vector<int> &nums, int k) {
    ll n = nums.size();
    V<ll> pfs(n + 1, 0);
    for (ll i = 0; i < n; ++i) {
      pfs[i + 1] = nums[i];
    }
    for (ll i = 1; i < pfs.size(); ++i) {
      pfs[i] += pfs[i - 1];
    }
    V<ll> mins(k, LLONG_MAX);
    for (ll i = 0; i < k; ++i) {
      mins[i] = min(mins[i], pfs[i]);
    }
    ll ans = LLONG_MIN;
    for (ll i = k; i <= n; ++i) {
      ll mod = i % k;
      ans = max(ans, pfs[i] - mins[mod]);
      mins[mod] = min(mins[mod], pfs[i]);
    }
    return ans;
  }
};
// @lc code=end
