#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1578 lang=cpp
 *
 * [1578] Minimum Time to Make Rope Colorful
 */

// @lc code=start
class Solution {
public:
  int minCost(string colors, vector<int> &neededTime) {
    int n = neededTime.size();
    vector<pair<int, int>> seg;
    int start = 0;
    for (int i = 1; i < n; ++i) {
      if (colors[i] != colors[i - 1]) {
        seg.push_back({start, i - 1});
        start = i;
      }
    }
    seg.push_back({start, n - 1});
    int ans = 0;
    for (auto &[x, y] : seg) {
      int mx = 0, tot = 0;
      for (int i = x; i <= y; ++i) {
        mx = max(mx, neededTime[i]);
        tot += neededTime[i];
      }
      ans += tot - mx;
    }
    return ans;
  }
};
// @lc code=end
