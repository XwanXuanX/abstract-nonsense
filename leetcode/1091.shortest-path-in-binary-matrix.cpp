#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1091 lang=cpp
 *
 * [1091] Shortest Path in Binary Matrix
 */

// @lc code=start
class Solution {
public:
  struct cord {
    int i;
    int j;
    int steps;
  };

  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, -1, 0, 1};

  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if (grid[0][0] == 1) {
      return -1;
    }
    int ans = INT_MAX;
    int n = grid.size();
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    queue<cord> q;
    q.push({0, 0, 1});
    vis[0][0] = true;
    while (!q.empty()) {
      auto [i, j, steps] = q.front(); q.pop();
      if (i == n - 1 && j == n - 1) {
        ans = min(ans, steps);
        continue;
      }
      for (int k = 0; k < 4; ++k) {
        for (int o = 0; o < 4; ++o) {
          int ni = i + dx[k], nj = j + dy[o];
          if (ni < 0 || ni >= n || nj < 0 || nj >= n || grid[ni][nj] || vis[ni][nj] || steps >= ans) {
            continue;
          }
          q.push({ni, nj, steps + 1});
          vis[ni][nj] = true;
        }
      }
    }
    if (ans == INT_MAX) {
      return -1;
    }
    return ans;
  }
};
// @lc code=end

