#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1033 lang=cpp
 *
 * [1033] Moving Stones Until Consecutive
 */

// @lc code=start
class Solution {
public:
  vector<int> numMovesStones(int a, int b, int c) {
    vector<int> t = {a, b, c};
    sort(t.begin(), t.end());
    a = t[0], b = t[1], c = t[2];
    vector<int> ans(2);
    if (a + 1 == b && b + 1 == c) {
      ans[0] = 0;
    } else {
      ans[0] = (a + 1 == b || a + 2 == b || b + 1 == c || b + 2 == c) ? 1 : 2;
    }
    ans[1] = c - b - 1 + b - a - 1;
    return ans;
  }
};
// @lc code=end
