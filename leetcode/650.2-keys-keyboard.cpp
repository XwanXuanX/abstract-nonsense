#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 */

// @lc code=start
class Solution {
public:
  int minSteps(int n) {
    vector<int> dp(n+1, INT_MAX);
    dp[1] = 0;
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        if (i % j == 0) {
          dp[i] = min(dp[i], dp[j] + i/j);
        }
      }
    }
    return dp[n];
  }
};
// @lc code=end

