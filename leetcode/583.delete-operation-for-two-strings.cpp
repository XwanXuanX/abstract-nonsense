#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 */

// @lc code=start
class Solution {
public:
  template <class T> using V = vector<T>;
  int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    V<V<int>> dp(n + 1, V<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (word1[i-1] == word2[j-1]) {
          dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }
        dp[i][j] = max({dp[i][j], dp[i-1][j], dp[i][j-1]});
      }
    }
    return n - dp[n][m] + m - dp[n][m];
  }
};
// @lc code=end

