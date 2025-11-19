#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
public:
  template <class T> using V = vector<T>;

  // We have 9 squares, thus 9 sets
  unordered_set<int> sqs[3][3];
  // We have 9 rows, and 9 columns
  unordered_set<int> rows[9];
  unordered_set<int> cols[9];

  // int r = i / 3;
  // int c = j / 3;

  bool solve(V<V<char>> &board, V<pair<int, int>> &todo, int i) {
    if (i == todo.size()) {
      return true;
    }
    auto [r, c] = todo[i];
    // Now we can try 1-9
    for (int tr = 1; tr <= 9; ++tr) {
      // Determine if we can put tr at (r, c)
      if (sqs[r / 3][c / 3].contains(tr) || rows[r].contains(tr) ||
          cols[c].contains(tr)) {
        continue;
      }
      // Put tr at (r, c)
      const char original = board[r][c];
      board[r][c] = (char)(tr + '0');
      sqs[r / 3][c / 3].insert(tr), rows[r].insert(tr), cols[c].insert(tr);
      if (solve(board, todo, i + 1)) {
        return true;
      }
      // Otherwise, we need to backtrack
      board[r][c] = original;
      sqs[r / 3][c / 3].erase(tr), rows[r].erase(tr), cols[c].erase(tr);
    }
    // Nothign worked...
    return false;
  }

  void solveSudoku(vector<vector<char>> &board) {
    int n = board.size(), m = board[0].size();
    V<pair<int, int>> todo;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (board[i][j] == '.') {
          todo.push_back({i, j});
        } else {
          sqs[i / 3][j / 3].insert(board[i][j] - '0'),
              rows[i].insert(board[i][j] - '0'),
              cols[j].insert(board[i][j] - '0');
        }
      }
    }
    assert(solve(board, todo, 0));
  }
};
// @lc code=end
