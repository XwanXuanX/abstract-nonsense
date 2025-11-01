#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution {
public:
  int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, INT_MIN));
    dp[0][0] = 0, dp[0][1] = -prices[0];
    for (int i = 1; i < n; ++i) {
      // No stock in hand
      dp[i][0] = max(dp[i][0], max(dp[i-1][0], dp[i-1][1] + prices[i] - fee));
      // Has stock in hand
      dp[i][1] = max(dp[i][1], max(dp[i-1][1], dp[i-1][0] - prices[i]));
    }
    return max(dp[n-1][0], dp[n-1][1]);
  }
};
// @lc code=end

