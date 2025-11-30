#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1590 lang=cpp
 *
 * [1590] Make Sum Divisible by P
 */

// @lc code=start
class Solution {
public:
  using ll = long long;
  int minSubarray(vector<int> &nums, int p) {
    ll n = nums.size();
    ll tot = accumulate(nums.begin(), nums.end(), 0ll);
    // The subarray sum mod p needs to be this
    ll need = tot % p;
    if (need == 0) {
      return 0;
    }
    nums[0] %= p;
    for (ll i = 1; i < n; ++i) {
      nums[i] = ((nums[i] % p) + (nums[i - 1] % p)) % p;
    }
    ll ans = LLONG_MAX;
    unordered_map<ll, ll> ind;
    ind[0] = -1;
    for (ll i = 0; i < n; ++i) {
      ll y = nums[i] - need;
      y = y < 0 ? (y + p) % p : y % p;
      if (ind.count(y)) {
        ans = min(ans, i - ind[y]);
      }
      ind[nums[i]] = max(ind[nums[i]], i);
    }
    return ans == n ? -1 : ans;
  }
};
// @lc code=end
