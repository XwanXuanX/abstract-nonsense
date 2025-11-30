#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=370 lang=cpp
 *
 * [370] Range Addition
 */

// @lc code=start
class Solution {
public:
  vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
    vector<int> ans(length, 0);
    for (auto &u : updates) {
      int start = u[0], end = u[1], inc = u[2];
      if (end < length - 1) {
        ans[end + 1] -= inc;
      }
      ans[start] += inc;
    }
    for (int i = 1; i < length; ++i) {
      ans[i] += ans[i - 1];
    }
    return ans;
  }
};
// @lc code=end
