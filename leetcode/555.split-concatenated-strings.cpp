#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=555 lang=cpp
 *
 * [555] Split Concatenated Strings
 */

// @lc code=start
class Solution {
public:
  string lookRight(vector<string>& strs, int i, int j, int n) {
    string right;
    right.push_back(strs[i][j]);
    right.append(strs[i].substr(j + 1, strs[i].size()));
    for (int k = (i + 1) % n; k != i; k = (k + 1) % n) {
      string rev = strs[k];
      reverse(rev.begin(), rev.end());
      right.append(max(strs[k], rev));
    }
    right.append(strs[i].substr(0, j));
    return right;
  }

  string splitLoopedString(vector<string>& strs) {
    int n = strs.size();
    string ans;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < strs[i].size(); ++j) { // O(1e3)
        ans = max(ans, lookRight(strs, i, j, n));
      }
      reverse(strs[i].begin(), strs[i].end());
      for (int j = 0; j < strs[i].size(); ++j) {
        ans = max(ans, lookRight(strs, i, j, n));
      }
    }
    return ans;
  }
};
// @lc code=end

