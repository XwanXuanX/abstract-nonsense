#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
class Solution {
public:
  template <class T> using V = vector<T>;
  V<V<int>> dp;

  bool backtrack(string &s, string &p, int i, int j) {
    if (dp[i][j] != -1) {
      return dp[i][j];
    }
    if (j == p.size()) {
      return dp[i][j] = i == s.size();
    }
    if (i == s.size()) {
      for (int k = j; k < p.size(); ++k) {
        if (p[k] != '*') {
          return dp[i][j] = 0;
        }
      }
      return dp[i][j] = 1;
    }

    if (p[j] == s[i] || p[j] == '?') {
      return dp[i][j] = backtrack(s, p, i + 1, j + 1);
    }
    if (p[j] == '*') {
      if (backtrack(s, p, i + 1, j) || backtrack(s, p, i, j + 1)) {
        return dp[i][j] = 1;
      }
      return dp[i][j] = 0;
    }
    return dp[i][j] = 0;
  }

  bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    dp.assign(n + 1, V<int>(m + 1, -1));
    return backtrack(s, p, 0, 0);
  }
};
// @lc code=end
