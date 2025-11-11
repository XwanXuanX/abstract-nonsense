#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1981 lang=cpp
 *
 * [1981] Minimize the Difference Between Target and Chosen Elements
 */

// @lc code=start
class Solution {
public:
  template <class T> using V = vector<T>;
  int minimizeTheDifference(vector<vector<int>> &mat, int target) {
    int n = mat.size(), m = mat[0].size();
    V<V<int>> dp(n, V<int>(target + 1, 0));
    // For each target, we need to find the best element in the first row
    // That yield the minimum difference
    for (int t = 1; t <= target; ++t) {
      int mn = INT_MAX, mni = 0;
      for (int j = 0; j < m; ++j) {
        if (abs(mat[0][j] - t) < mn) {
          mn = abs(mat[0][j] - t);
          mni = mat[0][j];
        }
      }
      dp[0][t] = mni;
    }
    for (int i = 1; i < n; ++i) {
      for (int t = 1; t <= target; ++t) {
        int mn = INT_MAX, mni = 0;
        for (int j = 0; j < m; ++j) {
          int prev_target = max(t - mat[i][j], 1);
          int cur_sum = dp[i - 1][prev_target] + mat[i][j];
          if (abs(cur_sum - t) < mn) {
            mn = abs(cur_sum - t);
            mni = cur_sum;
          }
        }
        dp[i][t] = mni;
      }
    }
    return abs(target - dp[n - 1][target]);
  }
};
// @lc code=end
