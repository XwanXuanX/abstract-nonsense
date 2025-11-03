#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=3573 lang=cpp
 *
 * [3573] Best Time to Buy and Sell Stock V
 */

// @lc code=start
class Solution {
public:
  template <class T> using V = vector<T>;
  long long maximumProfit(vector<int> &prices, int k) {
    long long n = prices.size();
    V<V<V<long long>>> dp(n + 1, V<V<long long>>(k + 1, V<long long>(3, 0)));
    for (long long i = 0; i <= k; ++i) {
      dp[0][i][0] = 0;
      dp[0][i][1] = dp[0][i][2] = INT_MIN;
    }
    for (long long i = 1; i <= n; ++i) {
      for (long long j = 0; j <= k; ++j) {
        for (long long o = 0; o < 3; ++o) {
          long long take = INT_MIN;
          long long dontTake = dp[i - 1][j][o];
          if (o == 0) {
            take = max(take, dp[i - 1][j][0]);
            if (j > 0) {
              take = max(take, dp[i - 1][j - 1][1] + prices[i - 1]);
              take = max(take, dp[i - 1][j - 1][2] - prices[i - 1]);
            }
          } else if (o == 1) {
            take = max(take, dp[i - 1][j][0] - prices[i - 1]);
          } else {
            take = max(take, dp[i - 1][j][0] + prices[i - 1]);
          }
          dp[i][j][o] = max(take, dontTake);
        }
      }
    }
    return dp[n][k][0];
  }
};
// @lc code=end
