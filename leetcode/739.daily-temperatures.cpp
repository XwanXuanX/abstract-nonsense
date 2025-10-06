#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> stk;
    int n = temperatures.size();
    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; --i) {
      while (stk.size() && temperatures[i] >= temperatures[stk.top()]) {
        stk.pop();
      }
      if (stk.empty()) {
        stk.push(i);
        continue;
      }
      ans[i] = stk.top() - i;
      stk.push(i);
    }
    return ans;
  }
};
// @lc code=end

