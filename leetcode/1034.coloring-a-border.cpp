#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1034 lang=cpp
 *
 * [1034] Coloring A Border
 */

// @lc code=start
class Solution {
public:
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col,
                                  int color) {
    int n = grid.size(), m = grid[0].size();
    auto copy = grid;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    vis[row][col] = true;
    q.push({row, col});
    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();
      for (int k = 0; k < 4; ++k) {
        int ni = i + dx[k], nj = j + dy[k];
        if (ni < 0 || ni >= n || nj < 0 || nj >= m || vis[ni][nj] ||
            grid[ni][nj] != grid[i][j]) {
          if (ni < 0 || ni >= n || nj < 0 || nj >= m ||
              grid[ni][nj] != grid[i][j]) {
            copy[i][j] = color;
          }
          continue;
        }
        vis[ni][nj] = true;
        q.push({ni, nj});
      }
    }
    return copy;
  }
};
// @lc code=end
