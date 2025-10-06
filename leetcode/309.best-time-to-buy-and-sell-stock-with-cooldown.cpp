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
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> dp(n, 0);
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        int prof = prices[i] - prices[j] + (j - 2 >= 0 ? dp[j-2] : 0);
        dp[i] = max(dp[i], prof);
      }
      dp[i] = max(dp[i], dp[i-1]);
    }
    return dp[n-1];
  }
};
// @lc code=end

