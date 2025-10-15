#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
public:
  int countSubstrings(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    // Odd length substring
    int ans = n;
    for (int i = 0; i < n; ++i) {
      dp[i][i] = true;
    }
    for (int i = 1; i < n - 1; ++i) {
      for (int j = 1; j < n; ++j) {
        if (i - j < 0 || i + j >= n) {
          break;
        }
        int l = i - j, r = i + j;
        if (dp[l+1][r-1] && s[l] == s[r]) {
          ans++;
          dp[l][r] = true;
        }
      }
    }
    // Even length substring
    for (int i = 1; i < n; ++i) {
      if (s[i-1] == s[i]) {
        ans++;
        dp[i-1][i] = true;
      }
    }
    for (int i = 1; i < n - 1; ++i) {
      for (int j = 1; j < n; ++j) {
        if (i - j < 0 || i + 1 + j >= n) {
          break;
        }
        int l = i - j, r = i + 1 + j;
        if (dp[l+1][r-1] && s[l] == s[r]) {
          ans++;
          dp[l][r] = true;
        }
      }
    }
    return ans;
  }
};
// @lc code=end

