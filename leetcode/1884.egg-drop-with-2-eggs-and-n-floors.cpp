#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1884 lang=cpp
 *
 * [1884] Egg Drop With 2 Eggs and N Floors
 */

// @lc code=start
class Solution {
public:
  int dp[1001] = {};

  int twoEggDrop(int n) {
    if (dp[n] != 0) {
      return dp[n];
    }
    dp[n] = n;
    for (int i = 1; i < n; ++i) {
      dp[n] = min(dp[n], max(i - 1, twoEggDrop(n - i)) + 1);
    }
    return dp[n];
  }
};
// @lc code=end

