#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=2100 lang=cpp
 *
 * [2100] Find Good Days to Rob the Bank
 */

// @lc code=start
class Solution {
public:
  vector<int> goodDaysToRobBank(vector<int>& security, int time) {
    int n = security.size();
    vector<int> inc(n, 0), dec(n, 0);
    for (int i = 1; i < n; ++i) {
      if (security[i] <= security[i-1])
        dec[i] = dec[i-1] + 1;
    }
    for (int i = n - 2; i >= 0; --i) {
      if (security[i] <= security[i+1])
        inc[i] = inc[i+1] + 1;
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      if (inc[i] >= time && dec[i] >= time)
        ans.push_back(i);
    }
    return ans;
  }
};
// @lc code=end

