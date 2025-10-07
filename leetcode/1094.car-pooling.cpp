#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
class Solution {
public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    int mxDist = 0;
    for (auto& trip : trips) {
      mxDist = max(mxDist, trip[2]);
    }
    vector<int> pfs(mxDist + 1, 0);
    for (auto& trip : trips) {
      pfs[trip[1]] += trip[0];
      pfs[trip[2]] -= trip[0];
    }
    for (int i = 1; i < pfs.size(); ++i) {
      pfs[i] += pfs[i-1];
    }
    for (int i = 0; i < pfs.size(); ++i) {
      if (pfs[i] > capacity) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end

