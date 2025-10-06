#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
public:
  int prof(vector<int>& p, int i, int j) {
    return p[j] - p[i];
  }

  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<pair<int,int>> seg;
    int start = 0;
    for (int i = 1; i < n; ++i) {
      if (prices[i] < prices[i-1]) {
        if (start < i - 1) {
          seg.push_back({start, i-1});
        }
        start = i;
      }
    }
    if (start < n - 1) {
      seg.push_back({start, n-1});
    }
    int ans = 0;
    // upper bound
    for (const auto& p : seg) {
      ans += prices[p.second] - prices[p.first];
    }
    // remove the illegal cool down days
    for (int i = 1; i < seg.size(); ++i) {
      auto& p = seg[i-1], &q = seg[i];
      if (q.first == p.second + 1) {
        if (p.first == p.second)
          continue;
        // Then you have to decide which side to throw away
        int l = prof(prices, p.first, p.second - 1) + prof(prices, q.first, q.second);
        int r = prof(prices, p.first, p.second) + prof(prices, q.first + 1, q.second);
        if (l > r) { // throw away left is better
          ans = ans - prof(prices, p.first, p.second) + prof(prices, p.first, p.second - 1);
          p.second -= 1;
        } else { // throw away right is better
          ans = ans - prof(prices, q.first, q.second) + prof(prices, q.first + 1, q.second);
          q.first += 1;
        }
      }
    }
    return ans;
  }
};
// @lc code=end

