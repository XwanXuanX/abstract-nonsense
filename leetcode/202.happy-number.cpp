#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
public:
  set<int> seen;
  
  int getDigs(int n) {
    int sum = 0;
    while (n) {
      sum += (n % 10) * (n % 10);
      n /= 10;
    }
    return sum;
  }

  bool isHappy(int n) {
    while (!seen.contains(n) && n != 1) {
      seen.insert(n);
      n = getDigs(n);
    }
    return n == 1;
  }
};
// @lc code=end

