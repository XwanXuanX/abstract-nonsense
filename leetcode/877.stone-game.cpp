#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 */

// @lc code=start
class Solution {
public:
  bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
      dp[i][i] = piles[i];
    }
    for (int len = 2; len <= n; ++len) {
      for (int i = 0; i < n - len + 1; ++i) {
        int j = i + len - 1;
        // You have two choices, take the left end or right end
        dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1]);
      }
    }
    return dp[0][n-1] > 0 ? true : false;
  }
};
// @lc code=end

