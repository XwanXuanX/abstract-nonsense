#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1003 lang=cpp
 *
 * [1003] Check If Word Is Valid After Substitutions
 */

// @lc code=start
class Solution {
public:
  bool isValid(string s) {
    stack<char> stk;
    for (char c : s) {
      if (stk.empty()) {
        stk.push(c);
      } else {
        int top = stk.top();
        if (top == 'a') {
          if (c == 'a') {
            stk.push(c);
          } else if (c == 'b') {
            stk.pop();
            stk.push('B');
          } else {
            return false;
          }
        } else if (top == 'b' || top == 'c') {
          return false;
        } else {
          assert(top == 'B');
          if (c == 'a' || c == 'b') {
            stk.push(c);
          } else {
            stk.pop();
          }
        }
      }
    }
    return stk.empty();
  }
};
// @lc code=end
