#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1062 lang=cpp
 *
 * [1062] Longest Repeating Substring
 */

// @lc code=start
class Solution {
public:
  int longestRepeatingSubstring(string s) {
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        if (s[i - 1] == s[j - 1]) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
          ans = max(ans, dp[i][j]);
        }
      }
    }
    return ans;
  }
};
// @lc code=end
