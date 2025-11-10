#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1105 lang=cpp
 *
 * [1105] Filling Bookcase Shelves
 */

// @lc code=start
class Solution {
public:
  template <class T> using V = vector<T>;
  int minHeightShelves(vector<vector<int>> &books, int shelfWidth) {
    int n = books.size();
    V<int> dp(n + 1, 2e9);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
      int wid = 0, mxh = 0;
      for (int j = i; j > 0; --j) {
        wid += books[j - 1][0];
        if (wid > shelfWidth) {
          break;
        }
        mxh = max(mxh, books[j - 1][1]);
        dp[i] = min(dp[i], dp[j - 1] + mxh);
      }
    }
    return dp[n];
  }
};
// @lc code=end
