#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=348 lang=cpp
 *
 * [348] Design Tic-Tac-Toe
 */

// @lc code=start
class TicTacToe {
public:
  vector<int> rows, cols;
  int diag, anti;

  TicTacToe(int n) {
    rows.assign(n, 0);
    cols.assign(n, 0);
    diag = anti = 0;
  }
  
  int move(int row, int col, int player) {
    int cur = (player == 1) ? 1 : -1;
    rows[row] += cur;
    cols[col] += cur;
    if (row == col) {
      diag += cur;
    }
    int n = rows.size();
    if (row == n - col - 1) {
      anti += cur;
    }
    if (abs(rows[row]) == n || abs(cols[col]) == n || abs(diag) == n || abs(anti) == n) {
      return player;
    }
    return 0;
  }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
// @lc code=end

