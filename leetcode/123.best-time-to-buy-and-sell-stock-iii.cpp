#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
public:
  template <class T> using V = vector<T>;
  int maxProfit(vector<int> &prices) {
    long long n = prices.size();
    V<V<V<long long>>> dp(n + 1, V<V<long long>>(3, V<long long>(2, INT_MIN)));
    for (long long i = 0; i < 3; ++i) {
      dp[0][i][0] = 0;
      dp[0][i][1] = INT_MIN;
    }
    for (long long i = 1; i <= n; ++i) {
      for (long long j = 0; j < 3; ++j) {
        dp[i][j][0] =
            max(dp[i - 1][j][0],
                (j > 0) ? dp[i - 1][j - 1][1] + prices[i - 1] : INT_MIN);
        dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] - prices[i - 1]);
      }
    }
    return max(dp[n][2][0], dp[n][2][1]);
  }
};
// @lc code=end
