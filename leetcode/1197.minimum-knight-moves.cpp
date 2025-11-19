#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1197 lang=cpp
 *
 * [1197] Minimum Knight Moves
 */

// @lc code=start
class Solution {
public:
  struct cord {
    int i;
    int j;
    int step;
  };

  int dx[8] = {-1, -2, +1, +2, -2, +2, -1, +1};
  int dy[8] = {-2, -1, -2, -1, +1, +1, +2, +2};

  template <class T> using V = vector<T>;
  int minKnightMoves(int x, int y) {
    int sti = 350, stj = 0;
    x = abs(x), y = abs(y);
    x += sti, y += stj;
    V<V<bool>> vis(700, V<bool>(310, false));
    queue<cord> q;
    vis[sti][stj] = true;
    q.push({sti, stj, 0});
    while (q.size()) {
      auto [i, j, step] = q.front();
      if (i == x && j == y) {
        return step;
      }
      q.pop();
      // Push next steps
      for (int k = 0; k < 8; ++k) {
        int ni = i + dx[k], nj = j + dy[k];
        if (ni < 0 || ni >= 700 || nj < 0 || nj >= 310 || vis[ni][nj]) {
          continue;
        }
        vis[ni][nj] = true;
        q.push({ni, nj, step + 1});
      }
    }
    return 0;
  }
};
// @lc code=end
