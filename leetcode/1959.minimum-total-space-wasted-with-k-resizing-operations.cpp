#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1959 lang=cpp
 *
 * [1959] Minimum Total Space Wasted With K Resizing Operations
 */

// @lc code=start
class Solution {
public:
  template <class T> using V = vector<T>;
  int minSpaceWastedKResizing(vector<int> &nums, int k) {
    int n = nums.size();
    V<V<V<int>>> dp(n, V<V<int>>(n, V<int>(k + 1, 2e9)));
    for (int i = 0; i < n; ++i) {
      if (nums[i] >= nums[0]) {
        dp[0][i][0] = nums[i] - nums[0];
      }
    }
    for (int i = 1; i < n; ++i) {
      for (int o = 0; o <= k; ++o) {
        if (o == 0) {
          for (int j = 0; j < n; ++j) {
            if (nums[j] < nums[i]) {
              continue;
            }
            dp[i][j][o] = min(dp[i][j][o], dp[i - 1][j][o] + nums[j] - nums[i]);
          }
          continue;
        }
        V<int> mnl(n, 2e9), mnr(n, 2e9);
        mnl[0] = dp[i - 1][0][o - 1];
        mnr[n - 1] = dp[i - 1][n - 1][o - 1];
        for (int j = 1; j < n; ++j) {
          mnl[j] = min(mnl[j - 1], dp[i - 1][j][o - 1]);
        }
        for (int j = n - 2; j >= 0; --j) {
          mnr[j] = min(mnr[j + 1], dp[i - 1][j][o - 1]);
        }
        for (int j = 0; j < n; ++j) {
          if (nums[j] < nums[i]) {
            continue;
          }
          dp[i][j][o] = min(dp[i][j][o], dp[i - 1][j][o] + nums[j] - nums[i]);
          if (o > 0) {
            int leftmn = j > 0 ? mnl[j - 1] : 2e9;
            int rightmn = j < n - 1 ? mnr[j + 1] : 2e9;
            int mn = min(leftmn, rightmn);
            dp[i][j][o] = min(dp[i][j][o], mn + nums[j] - nums[i]);
          }
        }
      }
    }
    int ans = 2e9;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= k; ++j) {
        ans = min(ans, dp[n - 1][i][j]);
      }
    }
    return ans;
  }
};
// @lc code=end
