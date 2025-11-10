#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1072 lang=cpp
 *
 * [1072] Flip Columns For Maximum Number of Equal Rows
 */

// @lc code=start
class Solution {
public:
  int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    map<vector<pair<int, int>>, int> cnt;
    for (int i = 0; i < n; ++i) {
      auto &v = matrix[i];
      vector<pair<int, int>> seg;
      int start = 0;
      for (int j = 1; j < m; ++j) {
        if (v[j] != v[j - 1]) {
          seg.push_back({start, j - 1});
          start = j;
        }
      }
      seg.push_back({start, m - 1});
      cnt[seg]++;
    }
    int ans = 0;
    for (auto &p : cnt) {
      ans = max(ans, p.second);
    }
    return ans;
  }
};
// @lc code=end
