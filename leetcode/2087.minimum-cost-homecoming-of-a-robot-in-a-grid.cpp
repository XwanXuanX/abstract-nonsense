#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2087 lang=cpp
 *
 * [2087] Minimum Cost Homecoming of a Robot in a Grid
 */

// @lc code=start
class Solution {
public:
  int minCost(vector<int> &startPos, vector<int> &homePos,
              vector<int> &rowCosts, vector<int> &colCosts) {
    int si = startPos[0], sj = startPos[1];
    int hi = homePos[0], hj = homePos[1];
    // Find which column and rows must be crossed
    int ans = 0;
    if (si > hi) {
      for (int i = si - 1; i >= hi; --i) {
        ans += rowCosts[i];
      }
    } else if (hi > si) {
      for (int i = si + 1; i <= hi; ++i) {
        ans += rowCosts[i];
      }
    }
    if (sj > hj) {
      for (int i = sj - 1; i >= hj; --i) {
        ans += colCosts[i];
      }
    } else if (hj > sj) {
      for (int i = sj + 1; i <= hj; ++i) {
        ans += colCosts[i];
      }
    }
    return ans;
  }
};
// @lc code=end
