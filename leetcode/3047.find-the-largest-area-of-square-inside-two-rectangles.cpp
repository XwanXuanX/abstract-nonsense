#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=3047 lang=cpp
 *
 * [3047] Find the Largest Area of Square Inside Two Rectangles
 */

// @lc code=start
class Solution {
public:
  struct cube {
    vector<int> bot, top;
    string toString() {
      return "(" + to_string(bot[0]) + "," + to_string(bot[1]) + ")-(" +
             to_string(top[0]) + "," + to_string(top[1]) + ")";
    }
  };

  long long largestSquareArea(vector<vector<int>> &bottomLeft,
                              vector<vector<int>> &topRight) {
    long long n = bottomLeft.size();
    vector<cube> cubes;
    for (long long i = 0; i < n; ++i) {
      cubes.push_back({bottomLeft[i], topRight[i]});
    }

    long long ans = 0;
    for (long long i = 1; i < n; ++i) {
      for (long long j = 0; j < i; ++j) {
        // i is higher and more to the right than j
        auto &ci = cubes[i], &cj = cubes[j];
        long long xDist = min(ci.top[0], cj.top[0]) - max(ci.bot[0], cj.bot[0]);
        long long yDist = min(ci.top[1], cj.top[1]) - max(ci.bot[1], cj.bot[1]);
        if (xDist > 0 && yDist > 0) {
          long long side = min(xDist, yDist);
          ans = max(ans, side * side);
        }
      }
    }
    return ans;
  }
};
// @lc code=end
