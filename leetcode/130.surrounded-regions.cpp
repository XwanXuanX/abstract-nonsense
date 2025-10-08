#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
public:
  vector<vector<bool>> vis;
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  void dfs(int i, int j, vector<pair<int,int>>& space, vector<vector<char>>& board) {
    if (vis[i][j]) {
      return;
    }
    int n = board.size(), m = board[0].size();
    vis[i][j] = true;
    space.push_back({i, j});
    for (int k = 0; k < 4; ++k) {
      int ni = i + dx[k], nj = j + dy[k];
      if (ni < 0 || ni >= n || nj < 0 || nj >= m || vis[ni][nj] || board[ni][nj] == 'X') {
        continue;
      }
      dfs(ni, nj, space, board);
    }
  }

  bool surrounded(vector<pair<int,int>>& cord, int n, int m) {
    for (auto [x,y] : cord) {
      if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
        return false;
      }
    }
    return true;
  }

  void solve(vector<vector<char>>& board) {
    int n = board.size(), m = board[0].size();
    vis = vector<vector<bool>>(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (board[i][j] == 'X' || vis[i][j]) {
          continue;
        }
        vector<pair<int,int>> cords;
        dfs(i, j, cords, board);
        if (surrounded(cords, n, m)) {
          for (auto [x,y] : cords) {
            board[x][y] = 'X';
          }
        }
      }
    }
  }
};
// @lc code=end

