#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1007 lang=cpp
 *
 * [1007] Minimum Domino Rotations For Equal Row
 */

// @lc code=start
class Solution {
public:
  int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    int n = tops.size();
    int ans = INT_MAX;
    for (int k = 1; k <= 6; ++k) {
      int cnt = 0, topCnt = 0, botCnt = 0;
      for (int i = 0; i < n; ++i) {
        if (tops[i] == k || bottoms[i] == k) {
          cnt++;
        }
        if (tops[i] == k) {
          topCnt++;
        }
        if (bottoms[i] == k) {
          botCnt++;
        }
      }
      if (cnt == n) {
        ans = min({ans, topCnt, n - topCnt, botCnt, n - botCnt});
      }
    }
    if (ans == INT_MAX) {
      return -1;
    }
    return ans;
  }
};
// @lc code=end

