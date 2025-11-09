#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1057 lang=cpp
 *
 * [1057] Campus Bikes
 */

// @lc code=start
class Solution {
public:
  int dist(vector<int> &a, vector<int> &b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
  }

  vector<int> assignBikes(vector<vector<int>> &workers,
                          vector<vector<int>> &bikes) {
    int n = workers.size(), m = bikes.size();
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        arr.push_back({i, j});
      }
    }
    sort(arr.begin(), arr.end(), [&](pair<int, int> &a, pair<int, int> &b) {
      int adist = dist(workers[a.first], bikes[a.second]);
      int bdist = dist(workers[b.first], bikes[b.second]);
      if (adist != bdist) {
        return adist < bdist;
      }
      return a < b;
    });
    unordered_set<int> used;
    vector<int> ans(n, -1);
    for (auto &p : arr) {
      if (ans[p.first] == -1 && !used.contains(p.second)) {
        ans[p.first] = p.second;
        used.insert(p.second);
      }
    }
    return ans;
  }
};
// @lc code=end
