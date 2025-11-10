#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1937 lang=cpp
 *
 * [1937] Maximum Number of Points with Cost
 */

// @lc code=start
class Solution {
public:
  using ll = long long;
  template <class T> using V = vector<T>;

  long long maxPoints(vector<vector<int>> &points) {
    int n = points.size(), m = points[0].size();
    V<V<ll>> dp(n, V<ll>(m, INT_MIN));
    for (int i = 0; i < m; ++i) {
      dp[0][i] = points[0][i];
    }
    for (int i = 1; i < n; ++i) {
      V<ll> mx1(m, INT_MIN), mx2(m, INT_MIN);
      mx1[0] = dp[i - 1][0];
      for (int j = 1; j < m; ++j) {
        mx1[j] = max(mx1[j - 1], dp[i - 1][j] + j);
      }
      mx2[m - 1] = dp[i - 1][m - 1] - (m - 1);
      for (int j = m - 2; j >= 0; --j) {
        mx2[j] = max(mx2[j + 1], dp[i - 1][j] - j);
      }
      for (int j = 0; j < m; ++j) {
        dp[i][j] = max(dp[i][j], max(mx1[j] + points[i][j] - j,
                                     mx2[j] + points[i][j] + j));
      }
    }
    ll ans = INT_MIN;
    for (int i = 0; i < m; ++i) {
      ans = max(ans, dp[n - 1][i]);
    }
    return ans;
  }
};
// @lc code=end
