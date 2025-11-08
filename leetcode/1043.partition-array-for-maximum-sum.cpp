#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1043 lang=cpp
 *
 * [1043] Partition Array for Maximum Sum
 */

// @lc code=start
class Solution {
public:
  int maxSumAfterPartitioning(vector<int> &arr, int k) {
    int n = arr.size();
    arr.insert(arr.begin(), 0);
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= k; ++j) {
        if (i - j >= 0) {
          int mx = 0;
          for (int o = i - j + 1; o <= i; ++o) {
            mx = max(mx, arr[o]);
          }
          dp[i] = max(dp[i], dp[i - j] + mx * j);
        }
      }
    }
    return dp[n];
  }
};
// @lc code=end
