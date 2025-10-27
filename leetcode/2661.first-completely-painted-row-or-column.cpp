#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2661 lang=cpp
 *
 * [2661] First Completely Painted Row or Column
 */

// @lc code=start
class Solution {
public:
  int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    unordered_map<int, pair<int,int>> pos;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        pos[mat[i][j]] = {i, j};
      }
    }
    vector<int> rowCount(n, 0), colCount(m, 0);
    for (int k = 0; k < arr.size(); ++k) {
      auto [i, j] = pos[arr[k]];
      rowCount[i]++, colCount[j]++;
      if (rowCount[i] == m || colCount[j] == n) {
        return k;
      }
    }
    // Not reachable
    return 0;
  }
};
// @lc code=end

