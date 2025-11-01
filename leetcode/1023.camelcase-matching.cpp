#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1023 lang=cpp
 *
 * [1023] Camelcase Matching
 */

// @lc code=start
class Solution {
public:
  bool solve(string &q, string &p) {
    int i = 0, j = 0;
    while (i < q.size() && j < p.size()) {
      if (q[i] == p[j]) {
        i++, j++;
      } else {
        if (isupper(q[i])) {
          return false;
        }
        i++;
      }
    }
    if (j != p.size()) {
      return false;
    }
    for (; i < q.size(); ++i) {
      if (isupper(q[i])) {
        return false;
      }
    }
    return true;
  }

  vector<bool> camelMatch(vector<string> &queries, string pattern) {
    int n = queries.size();
    vector<bool> ans(n);
    for (int i = 0; i < n; ++i) {
      ans[i] = solve(queries[i], pattern);
    }
    return ans;
  }
};
// @lc code=end
