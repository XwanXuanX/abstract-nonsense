#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
class NumMatrix {
public:
  vector<vector<int>> prefix;

  NumMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    prefix = vector<vector<int>>(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        prefix[i][j] = matrix[i][j];
        if (i > 0) {
          prefix[i][j] += prefix[i-1][j];
        }
        if (j > 0) {
          prefix[i][j] += prefix[i][j-1];
        }
        if (i > 0 && j > 0) {
          prefix[i][j] -= prefix[i-1][j-1];
        }
      }
    }
  }
    
  int sumRegion(int row1, int col1, int row2, int col2) {
    int total = prefix[row2][col2];
    int top = (row1 > 0) ? prefix[row1 - 1][col2] : 0;
    int left = (col1 > 0) ? prefix[row2][col1 - 1] : 0;
    int overlap = (row1 > 0 && col1 > 0) ? prefix[row1 - 1][col1 - 1] : 0;
    int sum = total - top - left + overlap;
    return sum;
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

