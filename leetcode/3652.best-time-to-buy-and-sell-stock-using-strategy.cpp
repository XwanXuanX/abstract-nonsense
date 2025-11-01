#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=3652 lang=cpp
 *
 * [3652] Best Time to Buy and Sell Stock using Strategy
 */

// @lc code=start
class Solution {
public:
  long long maxProfit(vector<int> &prices, vector<int> &strategy, int k) {
    long long n = prices.size();
    long long base = 0;
    for (long long i = 0; i < n; ++i) {
      base += prices[i] * strategy[i];
    }
    long long ans = base, modify = base;
    for (long long i = 0; i < k; ++i) {
      modify -= strategy[i] * prices[i];
      if (i >= k / 2) {
        modify += prices[i];
      }
    }
    ans = max(ans, modify);
    for (long long l = 1, r = k; r < n; ++r, ++l) {
      modify -= strategy[r] * prices[r];
      modify += prices[r];
      modify += strategy[l - 1] * prices[l - 1];
      modify -= prices[l - 1 + k / 2];
      ans = max(ans, modify);
    }
    return ans;
  }
};
// @lc code=end
