#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=651 lang=cpp
 *
 * [651] 4 Keys Keyboard
 */

// @lc code=start
class Solution {
public:
  int maxA(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        // You can just press 'A'
        dp[i] = max(dp[i], dp[j] + (i - j));
        // Or you can copy and paste multiple times
        if (i - j > 2) {
          int paste = i - j - 2;
          dp[i] = max(dp[i], dp[j] * (paste + 1));
        }
      }
    }
    return dp[n];
  }
};
// @lc code=end

