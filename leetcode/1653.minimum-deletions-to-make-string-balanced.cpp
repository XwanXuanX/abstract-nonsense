#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1653 lang=cpp
 *
 * [1653] Minimum Deletions to Make String Balanced
 */

// @lc code=start
class Solution {
public:
  template <class T> using V = vector<T>;
  int minimumDeletions(string s) {
    int n = s.size();
    V<V<int>> dp(n, V<int>(3, 2e9));
    dp[0][0] = s[0] == 'b';
    dp[0][1] = s[0] == 'a';
    if (s[0] == 'b') {
      dp[0][2] = 0;
    }
    for (int i = 1; i < n; ++i) {
      if (s[i] == 'a') {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1] + 1;
        if (dp[i - 1][2] != 2e9) {
          dp[i][2] = dp[i - 1][2] + 1;
        }
      } else {
        dp[i][0] = dp[i - 1][0] + 1;
        dp[i][1] = dp[i - 1][1];
        if (dp[i - 1][2] == 2e9) {
          dp[i][2] = 0;
        } else {
          dp[i][2] = min(dp[i - 1][2], dp[i - 1][0]);
        }
      }
    }
    return min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
  }
};
// @lc code=end
