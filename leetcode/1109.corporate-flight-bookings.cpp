#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1109 lang=cpp
 *
 * [1109] Corporate Flight Bookings
 */

// @lc code=start
class Solution {
public:
  vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
    vector<int> pfs(n + 3, 0);
    for (auto &b : bookings) {
      int s = b[0], e = b[1], se = b[2];
      pfs[s] += se, pfs[e + 1] -= se;
    }
    for (int i = 1; i < pfs.size(); ++i) {
      pfs[i] += pfs[i - 1];
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
      ans.push_back(pfs[i]);
    }
    return ans;
  }
};
// @lc code=end
