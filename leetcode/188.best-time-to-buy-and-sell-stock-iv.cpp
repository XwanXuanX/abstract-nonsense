#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
class Solution {
public:
  template <class T> using V = vector<T>;
  int maxProfit(int k, vector<int> &prices) {
    int n = prices.size();
    V<V<V<int>>> dp(n + 1, V<V<int>>(k + 1, V<int>(2, INT_MIN)));
    for (int i = 0; i <= k; ++i) {
      dp[0][i][0] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= k; ++j) {
        dp[i][j][0] =
            max(dp[i - 1][j][0],
                (j > 0) ? dp[i - 1][j - 1][1] + prices[i - 1] : INT_MIN);
        dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] - prices[i - 1]);
      }
    }
    return dp[n][k][0];
  }
};
// @lc code=end
