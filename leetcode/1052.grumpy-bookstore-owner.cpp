#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1052 lang=cpp
 *
 * [1052] Grumpy Bookstore Owner
 */

// @lc code=start
class Solution {
public:
  int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
    int n = customers.size();
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      if (!grumpy[i]) {
        cur += customers[i];
      }
    }
    int ans = cur;
    for (int i = 0; i < minutes; ++i) {
      if (grumpy[i]) {
        cur += customers[i];
      }
    }
    ans = max(ans, cur);
    for (int l = 1, r = minutes; r < n; ++r, ++l) {
      if (grumpy[l - 1]) {
        cur -= customers[l - 1];
      }
      if (grumpy[r]) {
        cur += customers[r];
      }
      ans = max(ans, cur);
    }
    return ans;
  }
};
// @lc code=end
