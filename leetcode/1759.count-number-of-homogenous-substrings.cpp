#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1759 lang=cpp
 *
 * [1759] Count Number of Homogenous Substrings
 */

// @lc code=start
class Solution {
public:
  using ll = long long;
  static constexpr ll mod = 1e9 + 7;
  int countHomogenous(string s) {
    ll n = s.size();
    vector<pair<ll, ll>> seg;
    ll start = 0;
    for (ll i = 1; i < n; ++i) {
      if (s[i] != s[i - 1]) {
        seg.emplace_back(start, i - 1);
        start = i;
      }
    }
    seg.emplace_back(start, n - 1);
    ll ans = 0;
    for (auto &[l, r] : seg) {
      ll len = r - l + 1;
      ans = ((ans % mod) + ((len * (len + 1) / 2) % mod)) % mod;
    }
    return static_cast<ll>(ans);
  }
};
// @lc code=end
