#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1293 lang=cpp
 *
 * [1293] Shortest Path in a Grid with Obstacles Elimination
 */

// @lc code=start
class Solution {
public:
  struct cord {
    int i;
    int j;
    int step;
    int removed;
  };

  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  template <class T> using V = vector<T>;

  int shortestPath(vector<vector<int>>& grid, int k) {
    int n = grid.size(), m = grid[0].size();
    V<V<V<int>>> vis(n, V<V<int>>(m, V<int>(k + 1, 0)));
    deque<cord> q;
    vis[0][0][0] = 1;
    q.push_back({0, 0, 0, 0});
    int started = 0, ans = INT_MAX;
    while (!q.empty()) {
      started |= 1;
      auto [i, j, step, removed] = q.front(); q.pop_front();
      if (i == n - 1 && j == m - 1) {
        ans = min(ans, step);
        continue;
      }
      for (int o = 0; o < 4; ++o) {
        int ni = i + dx[o], nj = j + dy[o];
        if (ni < 0 || ni >= n || nj < 0 || nj >= m
            || (removed + grid[ni][nj] <= k && vis[ni][nj][removed + grid[ni][nj]])
            || (grid[ni][nj] && removed >= k)) {
          continue;
        }
        vis[ni][nj][removed + grid[ni][nj]] = 1;
        q.push_back({ni, nj, step + 1, removed + grid[ni][nj]});
      }
    }
    if (!started) return 0;
    if (ans == INT_MAX) return -1;
    return ans;
  }
};
// @lc code=end

