#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2361 lang=cpp
 *
 * [2361] Minimum Costs Using the Train Line
 */

// @lc code=start
class Solution {
public:
  using ll = long long;
  template <class T> using V = vector<T>;
  vector<long long> minimumCosts(vector<int> &regular, vector<int> &express,
                                 int expressCost) {
    int n = regular.size();
    V<V<ll>> dp(n, V<ll>(2, 1e18));
    dp[0][0] = regular[0];
    dp[0][1] = expressCost + express[0];
    for (int i = 1; i < n; ++i) {
      dp[i][0] = min(dp[i][0],
                     min(dp[i - 1][0] + regular[i], dp[i - 1][1] + regular[i]));
      dp[i][1] = min(dp[i][1], min(dp[i - 1][1] + express[i],
                                   dp[i - 1][0] + express[i] + expressCost));
    }
    V<ll> ans(n, 1e18);
    for (int i = 0; i < n; ++i) {
      ans[i] = min(dp[i][0], dp[i][1]);
    }
    return ans;
  }
};
// @lc code=end
